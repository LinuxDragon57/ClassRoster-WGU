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

    //The following functions are the default constructor, overloaded constructor, and the destructor - respectively.
    Student();
    Student(string&, string&, string&, string&, int, int[3], DegreeProgram);

    //The following are mutators for each instance variable
    void setStudentID(const string&);
    void setFirstName(const string&);
    void setLastName(const string&);
    void setEmail(const string&);
    void setAge(int);
    void setDaysInCourse(const int[3]);
    void setDegreeProgram(DegreeProgram);

    //The following are accessors for each instance variable
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    unsigned int getAge() const;
    int getAverageDaysInCourse() const;
    int getDaysInCourse() const;
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
