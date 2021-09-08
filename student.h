//
// Created by Tyler Gautney on 8/5/21.
//
#include<string>
#include "degree.h"
using namespace std;

#ifndef CLASSROSTER_STUDENT_H
#define CLASSROSTER_STUDENT_H

class Student {
public:

    //The default constructor and overloaded constructor, respectively.
    Student();
    Student(string, string, string, string, int, int*, DegreeProgram);


    //The following are mutators for each instance variable
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmail(string);
    void setAge(int);
    void setDaysInCourse(const int[3]);
    void setDegreeProgram(DegreeProgram);

    //The following are accessors for each instance variable
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getFullName() const;
    string getEmail() const;
    unsigned int getAge() const;
    int getAverageDaysInCourse() const;
    int getDaysInCourse(unsigned int) const;
    DegreeProgram getDegreeProgram() const;

    //The print function that does nothing but merely print the instance's values to standard output.
    void print() const;


private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    unsigned int age{};
    int daysInCourse[3]{};
    DegreeProgram degree;
};


#endif //CLASSROSTER_STUDENT_H
