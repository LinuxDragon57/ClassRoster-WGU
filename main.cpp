#include<iostream>
#include<string>
#include "roster.h"


// Function Prototypes
std::string ProgrammerInfo();


int main()
{

    std::cout << ProgrammerInfo();

    Roster classRoster{};
    // Add each student to classRoster
    classRoster.add((string &) "A1", (string&) "John", (string&) "Smith", (string&) "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
    classRoster.add((string&) "A2", (string&) "Suzan", (string&) "Erickson", (string&) "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
    classRoster.add((string&)"A3", (string&) "Jack", (string&) "Napoli", (string&) "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
    classRoster.add((string&)"A4", (string&) "Erin", (string&) "Black", (string&) "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
    classRoster.add((string&) "A5", (string&) "Tyler", (string&) "Gautney", (string&) "tyler.gautney@codedragon.dev", 22, 30, 35, 40, SOFTWARE);

    classRoster.printAll();
    classRoster.printInvalidEmails();

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

