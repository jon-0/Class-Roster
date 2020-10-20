#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int* numberOfDaysToCompleteEachCourse,
		DegreeType degreeType
	);

	DegreeType getDegreeProgram();
	void setDegreeProgram(DegreeType d);
	void print();

	// Destructor from Student 
	~SoftwareStudent();
};