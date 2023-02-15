#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "student.h"

//Defines default Student constructor
Student::Student() {
}
//Defines overloaded Student constructor with all necessary parameters
Student::Student(
	string uStudentID,
	string uFirstName,
	string uLastName,
	string uEmail,
	int uAge,
	int uDaysToCompleteCourses[3],
	DegreeProgram uDegreeProgram) {
	studentID = uStudentID;
	firstName = uFirstName;
	lastName = uLastName;
	email = uEmail;
	age = uAge;
    //iterates through input array parameter to set values of the array within the Student object
	for (int i = 0; i < MAX_COURSES; ++i) {
		daysToCompleteCourses[i] = uDaysToCompleteCourses[i];
	}
	degreeProgram = uDegreeProgram;
}

//Defines "get" mutator for studentID
string Student::GetStudentID() {
	return studentID;
}

//Defines "set" mutator for studentID
void Student::SetStudentID(string uStudentID) {
	studentID = uStudentID;
}

//Defines "get" mutator for firstName
string Student::GetFirstName() {
	return firstName;
}

//Defines "set" mutator for firstName
void Student::SetFirstName(string uFirstName) {
	firstName = uFirstName;
}

//Defines "get" mutator for lastName
string Student::GetLastName() {
	return lastName;
}

//Defines "set" mutator for lastName
void Student::SetLastName(string uLastName) {
	lastName = uLastName;
}

//Defines "get" mutator for email
string Student::GetEmail() {
	return email;
}

//Defines "set" mutator for email
void Student::SetEmail(string uEmail) {
	email = uEmail;
}

//Defines "get" mutator for age
int Student::GetAge() {
	return age;
}

//Defines "set" mutator for age
void Student::SetAge(int uAge) {
	age = uAge;
}

//Defines "get" mutator for daysToCompleteCourses which returns a pointer to the desired array
int *Student::GetDaysToCompleteCourse() {
	int *daysPointer = daysToCompleteCourses;
	return daysPointer;
}

//Defines "set" mutator for daysToCompleteCourses
void Student::SetDaysToCompleteCourses(int uDaysToCompleteCourses[3]) {
    //iterates through input array to set daysToCompleteCourses
	for (int i = 0; i < MAX_COURSES; ++i) {
		daysToCompleteCourses[i] = uDaysToCompleteCourses[i];
	}
}

//Defines "get" mutator for degreeProgram. **Note** this function is type DegreeProgram to allow it to return the appropriate value type
DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//Defines "set" mutator for degreeProgram
void Student::SetDegreeProgram(DegreeProgram uDegreeProgram) {
	degreeProgram = uDegreeProgram;
}

//Defines print function to print tab separated, specific student information
void Student::Print() {
	cout << studentID << "  ";
	cout << "First Name: " << firstName << "  ";
	cout << "Last Name: " << lastName << "  ";
	cout << "Age: " << age << "   ";
	cout << "daysInCourse: {";
    //iterates through daysToCompleteCourses array and meets desired output formatting
	for (int i = 0; i < (MAX_COURSES - 1); ++i) {
		cout << daysToCompleteCourses[i] << ", ";
	}
	cout << daysToCompleteCourses[MAX_COURSES - 1] << "}"
		 << "  ";
	cout << "Degree Program: ";
    //if/elseif statements used to acheive desired output formatting 
	if (degreeProgram == 0) {
		cout << "SECURITY";
	} else if (degreeProgram == 1) {
		cout << "NETWORK";
	} else if (degreeProgram == 2) {
		cout << "SOFTWARE";
	}
	cout << endl;
}
