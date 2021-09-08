#include<iostream>
#include<string>
#include <sstream>
#include "roster.h"


// Function Prototypes
std::string ProgrammerInfo();
void parseStudentData(Roster&);


int main()
{

    std::cout << ProgrammerInfo();

    Roster classRoster{};
    // Add each student to classRoster
    parseStudentData(classRoster);

    classRoster.printAll();
    std::cout << std::endl;
    classRoster.printInvalidEmails();
    std::cout << std::endl;

    // Loop through classRosterArray and for each element:
    // classRoster.printAverageDaysInCourse(current_object's studentID)
    for (int index=0; index<5; index++)
    {
        std::string StudentID = classRoster.getStudentObject(index);
        classRoster.printAverageDaysInCourse(StudentID);
    }


    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}


// This function sets my personal information so that main can print it to the screen.
// This method allows for easy formatting of the code for easier reading.
std::string ProgrammerInfo()
{
    std::string formatHeader = "****************************************\n";
    std::string courseTitle = "Scripting and Programming Applications\n";
    std::string programmingLang = "C++\n";
    std::string myStudentID = "#001400532\n";
    std::string myName = "Tyler Gautney\n";
    return formatHeader + courseTitle + programmingLang + myStudentID + myName + formatHeader + "\n";
}


void parseStudentData(Roster& obj)
{
    const string studentData[] =
            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,48,40,SECURITY",
             "A5,Tyler,Gautney,tyler.gautney@codedragon.dev,22,30,35,40,SOFTWARE"
            };
    char d = ','; //d for delimiter...
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degree;

    std::istringstream input;
    string tempStr;

    for (auto& index : studentData)
    {
        input.str(index);
        std::getline(input, studentID, d);
        std::getline(input, firstName, d);
        std::getline(input, lastName, d);
        std::getline(input, email, d);
        std::getline(input, tempStr, d);
        age = std::stoi(tempStr);
        for (auto& i : daysInCourse)
        {
            std::getline(input, tempStr, d);
            i = std::stoi(tempStr);
        }
        std::getline(input, tempStr, d);
        if (tempStr == "SECURITY")
            degree = SECURITY;
        else if (tempStr == "NETWORK")
            degree = NETWORK;
        else if (tempStr == "SOFTWARE")
            degree = SOFTWARE;

        obj.add(studentID, firstName, lastName, email, age, daysInCourse[0], daysInCourse[1], daysInCourse[2], degree);
    }
}