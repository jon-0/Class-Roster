#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent() :Student() // invoke super constructor
{
	setDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int * numberOfDaysToCompleteEachCourse, DegreeType degreeType)
	: Student(studentID, firstName, lastName, email, age, numberOfDaysToCompleteEachCourse, degreeType)
{
	setDegreeProgram(SOFTWARE);
}

DegreeType SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

// setter
void SoftwareStudent::setDegreeProgram(DegreeType d)
{
	this->type = SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student(); // call super destructor
	delete this;
}
