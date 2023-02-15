#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "roster.h"

// Defines default roster constructor
Roster::Roster() {
}

// Defines roster destructor
Roster::~Roster() {
	int i = 0;
	for (i = 0; i < ROSTER_SIZE; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
    cout << "Destructor Implemented" << endl;
}

// Defines add function to add studentData to Roster object
void Roster::add(
	string ustudentID,
	string uFirstName,
	string uLastName,
	string uemail,
	int uage,
	int udaysInCourse1,
	int udaysInCourse2,
	int udaysInCourse3,
	DegreeProgram uDegreeProgram) {
	int i;

	// Creates an array to hold days in each of 3 courses so they may be added
	// to Student objects.
	int daysToComplete[3] = {udaysInCourse1, udaysInCourse2, udaysInCourse3};
	for (i = 0; i < ROSTER_SIZE; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student;
			break;
		}
	}
	// Uses Student mutator functions to add information to student obejcts
	classRosterArray[i]->SetStudentID(ustudentID);
	classRosterArray[i]->SetFirstName(uFirstName);
	classRosterArray[i]->SetLastName(uLastName);
	classRosterArray[i]->SetEmail(uemail);
	classRosterArray[i]->SetAge(uage);
	classRosterArray[i]->SetDaysToCompleteCourses(daysToComplete);
	classRosterArray[i]->SetDegreeProgram(uDegreeProgram);
}
// Defines function to remove student data from the Roster Object
void Roster::remove(string studentID) {
	int i = 0;
	// bool value declared to assist in error message for non-existent stuent
	// information.
	bool j = false;
	for (i = 0; i < ROSTER_SIZE; ++i) {
		// Checks array element for null value before continuing.
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				j = true;
			}
		}
	}
	// Creates error message for non-existent studentID.
	if (j == false) {
		cout << "ERROR--Student ID: " << studentID << " not found." << endl;
	}
}
// Defines function to print all available student information.
void Roster::printAll() {
	for (int i = 0; i < ROSTER_SIZE; ++i) {
		// Checks array for null value before proceeding.
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}
// Defines function to print average days over 3 courses
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < ROSTER_SIZE; ++i) {
		// Checks array for null value
		if (classRosterArray[i] != nullptr) {
			// Compares studentIDs to find desired student information
			if (classRosterArray[i]->GetStudentID() == studentID) {
				// Gets pointer to daysToCompleteCourses array and dereferences
				// to access array elements.
				int *courseDays = {
					classRosterArray[i]->GetDaysToCompleteCourse()};
				// integer declared to hold sum of course days
				int total = 0;
				// sums days in 3 courses
				for (int j = 0; j < 3; ++j) {
					total += courseDays[j];
				}
				// print statement for average days in courses.
				cout << studentID
					 << "--Average days in course: " << ((total / 3)) << endl;
			}
		}
	}
}
// Defines function to print invalid emails
void Roster::printInvalidEmails() {
	cout << "Invalid Email Addresses:" << endl;
	for (int i = 0; i < ROSTER_SIZE; ++i) {
		// checks array for null value
		if (classRosterArray[i] != nullptr) {
			// declares temporary string to hold email
			string currEmail = classRosterArray[i]->GetEmail();
			// checks for "@", ".", and " " to verify valid email address
			if (currEmail.find("@") == string::npos) {
				cout << currEmail << endl;
			} else if (currEmail.find(".") == string::npos) {
				cout << currEmail << endl;
			} else if (currEmail.find(" ") != string::npos) {
				cout << currEmail << endl;
			}
		}
	}
}
// Defines function to print students by degree program.
void Roster::printByDegreeProgram(DegreeProgram uDegreeProgram) {
	// iterates through classRoster to find students with matching info
	for (int i = 0; i < ROSTER_SIZE; ++i) {
		// checks array for null value
		if (classRosterArray[i] != nullptr) {
			// checks to find matching degreeProgram
			if (classRosterArray[i]->GetDegreeProgram() == uDegreeProgram) {
				classRosterArray[i]->Print();
			}
		}
	}
}
// Defines function to get studentIDs via the Roster object. Allows
// iteration through classRoster in main to use any functions requiring a
// studentID parameter.
string Roster::GetStudentID(int uNextStudent) {
	string studentID = classRosterArray[uNextStudent]->GetStudentID();
	return studentID;
}
