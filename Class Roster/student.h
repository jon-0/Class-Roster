#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student//This class represents a Student
{
protected://protected items are visible to derived classes
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* numberOfDaysToCompleteEachCourse; // will be an array of size 3
	DegreeType type; // The enumerated value: Security, Networking, Software

public://public items are visible everywhere in the application
	const static int courseArraySize = 3;
	Student(); 	//empty constructor
	Student(string ID, string firstName, string lastName, string email, int age, int numberofDays[], DegreeType type); //full constructor

	//getters for each instance field
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumOfDays();
	virtual DegreeType getDegreeProgram() = 0; //VIRTUAL; cannot instantiate a Degree object

	//the setters
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumOfDays(int numOfDays[]);
	virtual void setDegreeProgram(DegreeType d) = 0; //VIRTUAL - you must initialize it to ZERO
	virtual void print() = 0;

	//The destructor
	~Student();
};
