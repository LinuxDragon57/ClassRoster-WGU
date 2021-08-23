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
}


Roster::~Roster()
{
        // Automatically iterate through the classRosterArray and delete the data within.
        for (auto& index : classRosterArray) delete index;
        // Delete the classRosterArray and the rosterIndex variables.
        delete *classRosterArray;
}


void Roster::add(string& studentID, string& firstName, string& lastName, string& emailAddress,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    /* The daysInCourseArray[] constructs an array using the daysInCourse parameters given to the function.
     * Then, for the rest of the parameters (and the newly constructed daysInCourseArray[]), it instantiates a new
     * Student class that is intended to be added to the classRosterArray of pointers. */
    int daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student addStudent(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);

    /* The function treats the roster like a stack. rosterIndex points to a different index in the classRosterArray
     * each time the function is run. rosterIndex starts at -1, as defined by the constructor, and this function
     * increments it to 0 before performing an operation using the local student instance variable. The next time the
     * function is run, rosterIndex should still be pointing to 0, and so the function will increment it once again to 1.
     * This creates an iterable approach despite the asynchronous connections to the function each time. */
    if (rosterIndex - 1 < 5) *classRosterArray[++rosterIndex] = addStudent;
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
         * overwrite the data with data from the next index until the loop reaches the end of the array -1
         * (because it is removing an element right now). */
        for (long unsigned int index=deleteIndex; index < sizeof(classRosterArray)-1; index++)
            classRosterArray[index] = classRosterArray[index + 1];
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
       printf("The average days in course for %s is %d.", classRosterArray[studentIndex]->getFirstName().c_str(),
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
    cout << "The following emails have failed to match proper email format:\n" << endl;
    for (index=0; index<5; index++)
    {
        /* The function only prints out emails whose corresponding index in the validEmails boolean array
         * is false. Thus, only invalid emails are printed to stdout. */
        if (!validEmails[index]) cout << studentEmails[index] << endl;
    }
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    DegreeProgram studentsDegrees[5];
    bool matchingDegrees[5]; // A boolean array that tells the function which students have the correct DegreeProgram.
    int index;

    // Grab each degree program in the class roster array, and add it to a local variable for easier indexing.
    for(index=0; index<5;index++) studentsDegrees[index] = classRosterArray[index]->getDegreeProgram();

    /* Assign a boolean value to each index of the matchingDegrees[] array. They correspond a respective index in
     * the classRosterArray. */
    for(index=0;index<5;index++)
    {
        if(studentsDegrees[index] == degreeProgram) matchingDegrees[index] = true;
        else matchingDegrees[index] = false;
    }

    /* Output a heading, and then iterate through the matchingDegrees[] array and print the information for each
     * student that has a matching degree using the student's print() method. */
    cout << "Students obtaining a(n) " << degreeProgram << "degree are: " << endl;
    for(index=0; index<5; index++)
    {
        if (matchingDegrees[index]) classRosterArray[index]->print();
        cout << endl;
    }

}


int Roster::getByID(const string& studentID)
{
    for (int index=0;index<5;index++)
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
    // Return the student located at the given index as specified by the function parameter.
    return classRosterArray[classRosterArrayIndex]->getStudentID();
}