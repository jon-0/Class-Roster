#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent() :Student()
{
	setDegreeProgram(NETWORKING);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int * numberOfDaysToCompleteEachCourse, DegreeType degreeType)
	: Student(studentID, firstName, lastName, email, age, numberOfDaysToCompleteEachCourse, degreeType)
{
	setDegreeProgram(NETWORKING);
}


DegreeType NetworkStudent::getDegreeProgram()
{
	return NETWORKING;
}

void NetworkStudent::setDegreeProgram(DegreeType d)
{
	this->type = NETWORKING;
}

void NetworkStudent::print()
{
	this->Student::print(); // calls the print method from the Student class
	cout << "NETWORKING" << "\n"; // print degree type
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student(); // call super destructor from Student in case it needs to release something
	delete this;
}