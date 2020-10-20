#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student // A NetworkStudent is a type of Student
{

public:
	// CONSTRUCTORS WILL CALL SUPERCONSTRUCTOR FROM Student

	NetworkStudent();
	NetworkStudent(
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
	~NetworkStudent();
};
