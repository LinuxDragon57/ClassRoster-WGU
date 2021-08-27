//
// Created by Tyler Gautney on 8/5/21.
//
#include<string>
#include "degree.h"
#include "student.h"
using namespace std;

#ifndef CLASSROSTER_ROSTER_H
#define CLASSROSTER_ROSTER_H


class Roster
        {
public:
    // Constructor and Destructor
    Roster();
    ~Roster();


    void add(const string&, const string&, const string&, const string&, int, int, int, int, DegreeProgram);
    void remove (const string&);
    void printAll();
    void printAverageDaysInCourse(const string&);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram);
    int getByID(const string&);
    string getStudentObject(int);


private:
    Student* classRosterArray[5]{};
    int rosterIndex;
    int classRosterSize;
};


#endif //CLASSROSTER_ROSTER_H
