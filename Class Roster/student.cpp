#include<iostream>
#include<iomanip>
#include "student.h"
using namespace std;


Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->numberOfDaysToCompleteEachCourse = new int[courseArraySize];
	for (int i = 0; i < courseArraySize; i++) this->numberOfDaysToCompleteEachCourse[i] = 0;

}

Student::Student(string ID, string firstName, string lastName, string email, int age, int numberofDays[], DegreeType type)
{
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->numberOfDaysToCompleteEachCourse = new int[courseArraySize];
	for (int i = 0; i < 3; i++) this->numberOfDaysToCompleteEachCourse[i] = numberofDays[i];
}

// Getters
string Student::getID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int * Student::getNumOfDays()
{
	return numberOfDaysToCompleteEachCourse;
}

// Setters
void Student::setID(string ID)
{
	studentID = ID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string author)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setNumOfDays(int numOfDays[])
{
	if (this->numberOfDaysToCompleteEachCourse != nullptr) {
		delete[] this->numberOfDaysToCompleteEachCourse;
		this->numberOfDaysToCompleteEachCourse = nullptr;
	}
	this->numberOfDaysToCompleteEachCourse = new int[courseArraySize];
	for (int i = 0; i < courseArraySize; i++)
		this->numberOfDaysToCompleteEachCourse[i] = numberOfDaysToCompleteEachCourse[i];
}

// prints all student data fields except degree type (Requirement 3E)
void Student::print()
{
	cout << studentID <<
		"\tFirst Name: " << firstName <<
		"\tLast Name: " << lastName <<
		"\tAge: " << age <<
		"\tdaysInCourse: {" << numberOfDaysToCompleteEachCourse[0] << ", " << numberOfDaysToCompleteEachCourse[1] << ", " << numberOfDaysToCompleteEachCourse[2] << "} ";
}

Student::~Student()
{

	if (numberOfDaysToCompleteEachCourse != nullptr) {
		delete[] numberOfDaysToCompleteEachCourse;
		numberOfDaysToCompleteEachCourse = nullptr;
	}
}

