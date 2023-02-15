#ifndef STUDENT_H
#define STUDENT_H
#endif
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "degree.h"

class Student {
public:
	// Default Student Constructor
	Student();
	// Overloaded Student Constructor including all neccessary variables:
	// StudentID, Name, Email, Age, Days to Complete Courses and Degree Program
	Student(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int daysToCompleteCourses[3],
		DegreeProgram degreeProgram);

	// mutator functions for StudentID
	string GetStudentID();
	void SetStudentID(string studentID);

	// mutator functions for First Name
	string GetFirstName();
	void SetFirstName(string firstName);

	// mutator functions for Last Name
	string GetLastName();
	void SetLastName(string lastName);

	// mutator functions for email
	string GetEmail();
	void SetEmail(string email);

	// mutator functions for age
	int GetAge();
	void SetAge(int age);

	// mutator functions for days to complete courses
	int *GetDaysToCompleteCourse();
	void SetDaysToCompleteCourses(int daysToCompleteCourses[3]);

	// mutator functions for DegreeProgram
	DegreeProgram GetDegreeProgram();
	void SetDegreeProgram(DegreeProgram degreeProgram);

	// print function to print all info
	void Print();

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;

	const int MAX_COURSES = 3;
	int daysToCompleteCourses[3];
	DegreeProgram degreeProgram;
};
