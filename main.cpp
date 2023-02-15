#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#include "roster.h"

// Student Data Input
int main() {
    const string studentData[] =
    
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,FirstName,LastName,email@someschool.edu,30,8,2,5,SOFTWARE"};
    
    // Required heading for Performance Task C867.
    cout << "Scripting and Programming-Applications -- C867" << endl;
    cout << "C++" << endl;
    cout << "WGU Student ID: 111111111" << endl;
    cout << "FirstName LastName" << endl;
    // Roster object declaration.
    Roster classRoster;
    // Degree Program object declared for use in following algorithm.
    DegreeProgram degreeProgram;
    // Iteration through student data array.
    for (int i = 0; i < sizeof(studentData) / sizeof(studentData[0]); ++i) {
        string sData = studentData[i];
        stringstream ss(sData);
        vector<string> addStudentData;
        // Parsing of student data.
        while (ss.good() == true) {
            string subSData;
            getline(ss, subSData, ',');
            addStudentData.push_back(subSData);
        }
        // uses input string to determine appropriate enumerated value Degree Program.
        if (addStudentData[8] == "SECURITY") {
            degreeProgram = SECURITY;
        } else if (addStudentData[8] == "NETWORK") {
            degreeProgram = NETWORK;
        } else if (addStudentData[8] == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        // Adds student data array information to classRoster
        classRoster.add(
                        addStudentData[0],
                        addStudentData[1],
                        addStudentData[2],
                        addStudentData[3],
                        stoi(addStudentData[4]),
                        stoi(addStudentData[5]),
                        stoi(addStudentData[6]),
                        stoi(addStudentData[7]),
                        degreeProgram);
    }
    // Prints all student data in tab separated format.
    classRoster.printAll();
    // Prints all invalid student emails.
    classRoster.printInvalidEmails();
    // Iterates through classRosterArray using a GetStudentID function defined in the Roster class.
    for (int i = 0; i < 5; ++i) {
        string nextStudent = classRoster.GetStudentID(i);
        classRoster.printAverageDaysInCourse(nextStudent);
    }
    // Prints all students by specified degree program.
    classRoster.printByDegreeProgram(SOFTWARE);
    // Removes student information by StudentID.
    classRoster.remove("A3");
    // Prints modified tab separated list of student information.
    classRoster.printAll();
    // Will print error message as A3 has already been removed.
    classRoster.remove("A3");

    return 0;
}

