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
    // This defines the classRosterArray of pointers and rosterIndex corresponds to a single index within the array.
    for (auto& index : classRosterArray) index = nullptr;
    rosterIndex = -1;
    classRosterSize = 5;
}


Roster::~Roster()
{
        // Automatically iterate through the classRosterArray and delete the data within.
        for (auto& index : classRosterArray) delete index;
        // Delete the classRosterArray and the rosterIndex variables.
        delete *classRosterArray;
}


void Roster::add(const string& studentID, const string& firstName, const string& lastName, const string& emailAddress,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    try
    {
        if (rosterIndex + 1 < 5) classRosterArray[++rosterIndex] =
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
    /* Here getByID() will take the studentID parameter and use that to return the index of the classRosterArray
     * that contains a matching string in the student's studentID class variable. deleteIndex is the index of the
     * student intended to be removed from the Class Roster.*/
    int deleteIndex = getByID(studentID);

    try
    {
        /* If getByID() returns a -1 instead of a positive integer, then that means that no student was found that
         * has a matching studentID with the one in the parameter. */
        if (deleteIndex == -1) throw runtime_error("Function, getByID(), returned -1. No matching student was found.");
        /* However, if getByID() returns a positive integer, then, starting at the index to delete, deleteIndex;
         * overwrite the data with data from the next index until the loop reaches the end of the array.
         * Finally, remove that index from the classRosterArray. */
        else
        {
            string name = classRosterArray[deleteIndex]->getFirstName() + ' ' + classRosterArray[deleteIndex]->getLastName();
            cout << "Removing student, " << name << ", from the class roster. Please wait...\n";

            for (unsigned int index=deleteIndex; index < classRosterSize; index++)
                classRosterArray[index] = classRosterArray[index + 1];
            this->classRosterSize--;
            cout << "Successfully removed, " << name << " from the class roster." << endl << endl;
        }
    }
    /* The function catches an exception if no matching student was found. This is it's exiting output when an
     * exception is found.*/
    catch(runtime_error& except)
    {
        cout << except.what() << endl;
        cout << "Cannot delete student from roster." << endl;
    }
}


void Roster::printAll()
{
    // Automatically index the classRosterArray and call the print() method for each student.
    for (auto& index : classRosterArray) index->print();
}


void Roster::printAverageDaysInCourse(const string& studentID)
{
    /* Here getByID() will take the studentID parameter and use that to return the index of the classRosterArray
     * that contains a matching string in the student's studentID class variable. studentIndex is the index of the
     * student whose course information need is needed. */
   int studentIndex = getByID(studentID);

   try
   {
       /* If getByID() returns a -1 instead of a positive integer, then that means that no student was found that has
        * a matching studentID with the one in the parameter. */
       if (studentIndex == -1) throw runtime_error("Function, getByID(), returned -1. No matching student was found.");
       // Output the average days in course for the student, formatted as such.
       printf("The average days in course for %s is %d.\n", classRosterArray[studentIndex]->getFirstName().c_str(),
              classRosterArray[studentIndex]->getAverageDaysInCourse());
   }
   catch(runtime_error& except)
   {
       /* The function catches an exception if no matching student was found. This is it's exiting output when an
        * exception is found. */
       cout << except.what() << endl;
       cout << "Cannot print average days in course." << endl;
   }
}


void Roster::printInvalidEmails()
{
    string studentEmails[5];
    // Emails must match the criteria set forth by the following Regular Expression.
    smatch validEmailMatches;
    regex validEmailCriteria(R"([\w_\.]+@\w+\.[a-z]{2,3})");
    bool validEmails[5]; // A boolean array that tells the function what email it should print out.
    int index;

    /* Get the email addresses of each student in the classRosterArray and save them to the indices
     * of an array with local scope. This makes it easier for the function to use only relevant data. */
    for (index=0; index<5; index++) studentEmails[index] = classRosterArray[index]->getEmail();

    /* Go through the emails in the studentEmails[] array, and check their strings against the Regex.
     * The output of the regex_match function will return either true or false, so set the
     * corresponding index within the validEmails[] array to the boolean output for each iteration of the loop. */
    for (index=0; index<5; index++) validEmails[index] = regex_match(studentEmails[index], validEmailCriteria);

    // Now, print out the invalid emails using the data collected by the last two for loops.
    cout << "The following emails have failed to match proper email format:" << endl;
    for (index=0; index<5; index++)
    {
        /* The function only prints out emails whose corresponding index in the validEmails boolean array
         * is false. Thus, only invalid emails are printed to stdout. */
        if (!validEmails[index]) cout << studentEmails[index] << endl;
    }
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    DegreeProgram studentDegree[5]; // An array that obtains degree information for each student.
    bool matchingDegrees[5]; // A boolean array that tells the function which students have the correct DegreeProgram.
    int index;

    // Grab each degree program in the class roster array, and add it to a local variable for easier indexing.
    for(index=0; index<5;index++) studentDegree[index] = classRosterArray[index]->getDegreeProgram();

    /* Assign a boolean value to each index of the matchingDegrees[] array. They correspond a respective index in
     * the classRosterArray. */
    for(index=0;index<5;index++)
    {
        if(studentDegree[index] == degreeProgram) matchingDegrees[index] = true;
        else matchingDegrees[index] = false;
    }

    /* Output a heading, and then iterate through the matchingDegrees[] array and print the information for each
     * student that has a matching degree using the student's print() method. */
    switch(degreeProgram)
    {
        case 0:
            cout << "\nStudents obtaining a Security degree are: " << endl;
            break;
        case 1:
            cout << "\nStudents obtaining a Netoworking degree are: " << endl;
            break;
        case 2:
            cout << "\nStudents obtaining a Software degree are: " << endl;
    }
    for(index=0; index<5; index++)
    {
        if (matchingDegrees[index]) classRosterArray[index]->print();
    }
    std::cout << std::endl;

}


int Roster::getByID(const string& studentID)
{
    for (int index=0;index<classRosterSize;index++)
    {
        /* Check every index in the classRosterArray and see if its studentID matches the one provided to the function
         * as a parameter. If the function finds a match, the index is sent back to the function that called it. If no
         * match is found, error code -1 is returned. */
        if (classRosterArray[index]->getStudentID() == studentID) return index;
    }
    return -1;
}

string Roster::getStudentObject(const int classRosterArrayIndex)
{
    // Return the student object located at the given index as specified by the function parameter.
    return classRosterArray[classRosterArrayIndex]->getStudentID();
}