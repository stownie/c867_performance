#ifndef ROSTER_H
#define ROSTER_H
#endif
#include <iostream>
using namespace std;
#include "student.h"

class Roster {
public:
	// Default Roster Constructor
	Roster();
	// Roster Destructor
	~Roster();

	// void function to add studentData to Roster object.
	void
	add(string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);

	// void function to remove student data given studentID
	void remove(string studentID);

	// void function to print all available student data
	void printAll();

	// void function to print a given student's average days over 3 courses
	void printAverageDaysInCourse(string studentID);

	// void function to print invalid emails
	void printInvalidEmails();

	// void function to print all students in a given degree program
	void printByDegreeProgram(DegreeProgram);

	// string function to return studentID's from the Roster obejct.
	string GetStudentID(int nextStudent);

private:
	int MAX_COURSES = 3;
	int ROSTER_SIZE = 5;

	Student *classRosterArray[5] = {nullptr,
									nullptr,
									nullptr,
									nullptr,
									nullptr};
};
