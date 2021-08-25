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
    setStudentID("");
    setFirstName("");
    setLastName("");
    setEmail("");
    setAge(0);
    int defaultDaysInCourse[3] = {0,1,2};
    setDaysInCourse(defaultDaysInCourse);
    setDegreeProgram(SOFTWARE);
}


//overloaded constructor
Student::Student(string studentID, string firstName, string lastName, string email,
                              int age, int daysInCourse[3], DegreeProgram degree)
{
    setStudentID(std::move(studentID));
    setFirstName(std::move(firstName));
    setLastName(std::move(lastName));
    setEmail(std::move(email));
    setAge(age);
    setDaysInCourse(daysInCourse);
    setDegreeProgram(degree);
}


//Class Mutators for each variable
void Student::setStudentID(string newID)
{
    this -> studentID = std::move(newID);
}


void Student::setFirstName(string newFirstName)
{
    this -> firstName = std::move(newFirstName);
}


void Student::setLastName(string newLastName)
{
    this -> lastName = std::move(newLastName);
}


void Student::setEmail(string newEmail)
{
    this -> email = std::move(newEmail);
}


void Student::setAge(int newAge)
{
    this -> age = newAge;
}


void Student::setDaysInCourse(const int updatedDaysInCourse[3])
{
    for (int index=0; index<3; index++)
        this -> daysInCourse[index] = updatedDaysInCourse[index];
}


void Student::setDegreeProgram(DegreeProgram updatedDegree)
{
    this -> degree = updatedDegree;
}


//Accessor Functions for each variable
string Student::getStudentID() const
{
    return studentID;
}


string Student::getFirstName() const
{
    return firstName;
}


string Student::getLastName() const
{
    return lastName;
}


string Student::getEmail() const
{
    return email;
}


unsigned int Student::getAge() const
{
    return age;
}


int Student::getAverageDaysInCourse() const
{
    int averageDaysInCourse = 0;
    for (int index : daysInCourse) averageDaysInCourse += index;
    averageDaysInCourse /= 3;
    return averageDaysInCourse;
}

int Student::getDaysInCourse(unsigned int index) const
{
    return daysInCourse[index];
}


DegreeProgram Student::getDegreeProgram() const
{
    return degree;
}


void Student::print() const
{
    cout << getStudentID() << "\t";
    cout << "First Name: " << getFirstName() << "\t";
    cout << "Last Name: " << getLastName() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "daysInCourse: {";
    for (int i=0; i<3; i++) cout << getDaysInCourse(i) << ',';
    cout <<"}\t";
    cout << "Degree Program: " << getDegreeProgram() << "\n\n";
}
