//
// Created by Tyler Gautney on 8/5/21.
//
#include<iostream>
#include<string>
#include <utility>
#include "student.h"
using namespace std;



//default constructor that sets all variables to empty strings
Student::Student()
{
    this->setStudentID("");
    this->setFirstName("");
    this->setLastName("");
    this->setEmail("");
    this->setAge(0);
    int defaultDaysInCourse[3] = {0,1,2};
    this->setDaysInCourse(defaultDaysInCourse);
    this->setDegreeProgram(NETWORK);
}


//overloaded constructor
Student::Student(string studentID, string firstName, string lastName, string email,
                              int age, int daysInCourse[3], DegreeProgram degree)
{
    // Using the move keyword from the std namespace prevents unnecessary copying of the variable
    // Ideally, I'd pass these strings as reference parameters, but this created a bug that caused a segmentation fault
    this->setStudentID(move(studentID));
    this->setFirstName(move(firstName));
    this->setLastName(move(lastName));
    this->setEmail(move(email));
    this->setAge(age);
    this->setDaysInCourse(daysInCourse);
    this->setDegreeProgram(degree);
}


//Class Mutators for each variable
void Student::setStudentID(string newID)
{
    this->studentID = move(newID);
}


void Student::setFirstName(string newFirstName)
{
    this->firstName = move(newFirstName);
}


void Student::setLastName(string newLastName)
{
    this->lastName = move(newLastName);
}


void Student::setEmail(string newEmail)
{
    this->email = move(newEmail);
}


void Student::setAge(int newAge)
{
    this->age = newAge;
}


void Student::setDaysInCourse(const int updatedDaysInCourse[3])
{
    for (int index=0; index<3; index++)
        this->daysInCourse[index] = updatedDaysInCourse[index];
}


void Student::setDegreeProgram(DegreeProgram updatedDegree)
{
    this->degree = updatedDegree;
}


//Accessor Functions for each variable
string Student::getStudentID() const
{
    return this->studentID;
}


string Student::getFirstName() const
{
    return this->firstName;
}


string Student::getLastName() const
{
    return this->lastName;
}

string Student::getFullName() const
{
    string fullName = this->getFirstName() + ' ' + this->getLastName();
    return fullName;
}


string Student::getEmail() const
{
    return this->email;
}


unsigned int Student::getAge() const
{
    return this->age;
}


int Student::getAverageDaysInCourse() const
{
    int averageDaysInCourse = 0;
    for (int index : this->daysInCourse) averageDaysInCourse += index;
    averageDaysInCourse /= 3;
    return averageDaysInCourse;
}

int Student::getDaysInCourse(unsigned int index) const
{
    return this->daysInCourse[index];
}


DegreeProgram Student::getDegreeProgram() const
{
    return this->degree;
}


void Student::print() const
{
    cout << this->getStudentID() << " \t";
    cout << "First Name: " << this->getFirstName() << " \t";
    cout << "Last Name: " << this->getLastName() << " \t";
    cout << "Age: " << this->getAge() << " \t";
    cout << "daysInCourse: {";
    for (int i=0; i<3; i++) cout << this->getDaysInCourse(i) << ',';
    cout <<"} \t";
    cout << "Degree Program: ";
    switch(this->getDegreeProgram())
    {
        case 0:
            cout << "Security" << endl;
            break;
        case 1:
            cout << "Networking" << endl;
            break;
        case 2:
            cout << "Software" << endl;
            break;
        default:
            cout << "Unspecified" << endl;
    }
}
