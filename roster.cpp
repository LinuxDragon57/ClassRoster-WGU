//
// Created by Tyler Gautney on 8/5/21.
//
#include<iostream>
#include<string>
#include<regex>
#include<stdexcept>
#include<stack>
#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;



Roster::Roster()
{
    // This defines the classRosterArray of pointers.
    for (auto& index : this->classRosterArray) index = nullptr;
    // rosterIndex corresponds to a single index within the array.
    // This variable is modified when the add function is called.
    this->rosterIndex = -1;
}


Roster::~Roster()
{
        for (int index=0; index < rosterIndex; index++) delete this->classRosterArray[index];
}


void Roster::add(const string& studentID, const string& firstName, const string& lastName, const string& emailAddress,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    try
    {
        if (this->rosterIndex + 1 < 5) this->classRosterArray[++this->rosterIndex] =
                new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);
        else throw runtime_error("Index out of range.");
    }
    catch(runtime_error& except)
    {
        cout << except.what() << endl;
        cout << "Cannot add anymore students to the roster." << endl;
    }
}


void Roster::remove(const string& studentID)
{
    int deleteIndex = this->getByID(studentID);

        if (deleteIndex == -1) cout << "Error: No student matching provided ID was found." << endl <<
                                       "Cannot remove student from the roster.";
        else
        {
            string name = this->classRosterArray[deleteIndex]->getFullName();
            cout << "Removing student, " << name << ", from the class roster. Please wait...\n";
            delete this->classRosterArray[deleteIndex];
            this->classRosterArray[deleteIndex] = this->classRosterArray[rosterIndex--];
            cout << "Successfully removed, " << name << " from the class roster." << endl << endl;
        }
}


void Roster::printAll()
{
    for (int index=0; index <= this->rosterIndex; index++) this->classRosterArray[index]->print();
}


void Roster::printAverageDaysInCourse(const string& studentID)
{
   int studentIndex = getByID(studentID);

       if (studentIndex == -1) cout << "Error: No student matching provided ID was found." << endl <<
                                        "Cannot print average days in course.";
       printf("The average days in course for %s is %d.\n", this->classRosterArray[studentIndex]->getFirstName().c_str(),
              this->classRosterArray[studentIndex]->getAverageDaysInCourse());
}


void Roster::printInvalidEmails()
{
    string studentEmails[5];
    smatch validEmailMatches;
    regex validEmailCriteria(R"([\w_\.]+@\w+\.[a-z]{2,3})");
    bool validEmails[5]; // A boolean array that tells the function what email it should print out.
    int index;

    for (index=0; index<5; index++) studentEmails[index] = this->classRosterArray[index]->getEmail();

    for (index=0; index<5; index++) validEmails[index] = regex_match(studentEmails[index], validEmailCriteria);

    cout << "The following emails have failed to match proper email format:" << endl;
    for (index=0; index<5; index++)
        if (!validEmails[index]) cout << studentEmails[index] << endl;
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    DegreeProgram studentDegree[5]; // An array that obtains degree information for each student.
    bool matchingDegrees[5]; // A boolean array that tells the function which students have the correct DegreeProgram.
    int index;

    for(index=0; index<5;index++) studentDegree[index] = this->classRosterArray[index]->getDegreeProgram();

    for(index=0;index<5;index++)
    {
        if(studentDegree[index] == degreeProgram) matchingDegrees[index] = true;
        else matchingDegrees[index] = false;
    }

    switch(degreeProgram)
    {
        case 0:
            cout << "\nStudents obtaining a Security degree are: " << endl;
            break;
        case 1:
            cout << "\nStudents obtaining a Networking degree are: " << endl;
            break;
        case 2:
            cout << "\nStudents obtaining a Software degree are: " << endl;
    }
    for(index=0; index<5; index++)
    {
        if (matchingDegrees[index]) this->classRosterArray[index]->print();
    }
    std::cout << std::endl;

}


int Roster::getByID(const string& studentID)
{
    try
    {
        if (this->rosterIndex > 0)
        {
            for (int index=0;index<=this->rosterIndex;index++)
            {
                if (this->classRosterArray[index]->getStudentID() == studentID) return index;
            }
        }
        else
            throw runtime_error("rosterIndex is less than 1.");
    }
    catch(runtime_error& except)
    {
            cout << except.what() << endl;
            cout << "There may not be any students in the roster.";
    }
    return -1;
}

string Roster::getStudentObject(const int classRosterArrayIndex)
{
    // Return the student object located at the given index as specified by the function parameter.
    return this->classRosterArray[classRosterArrayIndex]->getStudentID();
}