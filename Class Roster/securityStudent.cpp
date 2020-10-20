#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent() :Student()
{
	setDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int * numberOfDaysToCompleteEachCourse, DegreeType degreeType)
	: Student(studentID, firstName, lastName, email, age, numberOfDaysToCompleteEachCourse, degreeType) // invoke superconstructor
{
	setDegreeProgram(SECURITY);
}

DegreeType SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

// setter
void SecurityStudent::setDegreeProgram(DegreeType d)
{
	this->type = SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print(); // calls the print method from the Student class
	cout << "SECURITY" << "\n"; // print degree type
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student(); // call super destructor from Student in case it needs to release something
	delete this;
}