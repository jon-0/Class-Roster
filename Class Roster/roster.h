#pragma once
#include <string>
#include <iostream>
#include "student.h"

using std::string;

// Student Data Table - Input is 5 comma-delimited strings
extern const int numStudents = 5;

DegreeType returnDegreeTypeString(string d);

class Roster { // Requirement E - create a Roster class
public:

	Student* classRosterArray[numStudents];// Requirement E1 - classRosterArray is an array of pointers to students

	Roster(); // empty constructor initializes all fields to default values

	void add(int position, string studentID, string firstName, string lastName, string email, int age, int numDaysToComplete[], DegreeType d);

	void remove(string studentID); // removes a student from the roster based on ID

	void printAll(); // prints all student info using print() method from each student

	void printDaysInCourse(string studentID); // Prints student's average # of days in 3 courses

	void printInvalidEmails(); // Locates and prints invalid emails

	void printByDegreeProgram(DegreeType d); // Prints student info for the sepcified degree type

	~Roster(); // destroys roster and releases resources

};
