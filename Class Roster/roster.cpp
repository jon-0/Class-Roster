#include <iostream>
#include <string>
#include <sstream>
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "roster.h"

using std::cout;
using std::cerr;
using namespace std;

Roster::Roster() // empty constructor sets to default values
{
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i] = nullptr;
	}
}

DegreeType returnDegreeTypeString(string d)
{
	if (d == "NETWORK") {
		return NETWORKING;
	}
	else if (d == "SOFTWARE") {
		return SOFTWARE;
	}
	else {
		return SECURITY;
	}
}

// sets the instance variables from part D1 and updates the roster
void Roster::add(int i, string studentID, string firstName, string lastName, string email, int age, int numDaysToComplete[], DegreeType degree)
{
	switch (degree) {
	case NETWORKING:
		classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, email, age, numDaysToComplete, degree);
		break;
	case SECURITY:
		classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, email, age, numDaysToComplete, degree);
		break;
	case SOFTWARE:
		classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, email, age, numDaysToComplete, degree);
		break;
	}
}

void Roster::remove(string studentID)
{
	bool studentFound = false;
	for (int i = 0; i < numStudents; i++) { // search for student ID in classRosterArray
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getID() == studentID) {
				classRosterArray[i]->~Student();
				cout << "Successfully removed student ID: " + studentID + " from the class roster." << endl;
				classRosterArray[i] = nullptr;
				studentFound = true;
				break;
			}
		}
	}

	if (studentFound == false) {
		cout << "Error: student ID " + studentID + " not found in class roster." << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printDaysInCourse(string studentID)
{
	bool studentFound = false;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getID() == studentID) {
			studentFound = true;
			double sum = classRosterArray[i]->getNumOfDays()[0];
			sum += classRosterArray[i]->getNumOfDays()[1];
			sum += classRosterArray[i]->getNumOfDays()[2];
			cout << classRosterArray[i]->getFirstName() + "'s average number of days in three courses: " << sum / 3 << endl;
			break;
		}

	}

	if (studentFound == false) {
		cout << "Error: student ID " + studentID + " not found in class roster." << endl;
	}


}

void Roster::printInvalidEmails()
{
	cout << "\nPrinting invalid emails..." << endl;

	// A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	for (int i = 0; i < numStudents; i++) {

		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->getEmail();

			bool isValid = true;

			if (email.find("@") == string::npos) {
				isValid = false;
			}
			if (email.find(".") == string::npos) {
				isValid = false;
			}
			if (email.find(" ") != string::npos) {
				isValid = false;
			}

			if (isValid == false) {
				cout << "The following email is invalid: " + email << endl;
			}
		}

	}
}

string getEnumDegreeString(DegreeType d) {
	if (d == NETWORKING) {
		return "NETWORKING";
	}
	else if (d == SOFTWARE) {
		return "SOFTWARE";
	}
	else {
		return "SECURITY";
	}
}

void Roster::printByDegreeProgram(DegreeType d)
{
	cout << "\nPrinting " << getEnumDegreeString(d) << " student info..." << endl;


	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getDegreeProgram() == d) {
				classRosterArray[i]->print();
			}
		}

	}

	cout << endl;
}

Roster::~Roster()
{
}



int main()
{
	//Prints my student info as required in F1.
	cout << "********* My Student Info ***********" << endl;
	cout << "Course Title: Scripting & Programming - Applications - C867" << endl;
	cout << "Programming Language Used: C++ via Microsoft Visual Studio" << endl;
	cout << "Student ID: #000877672" << endl;
	cout << "Student Name: Jonathan Otano" << endl << endl;

	// Student Data Table
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jonathan,Otano,jotano1@wgu.edu,27,25,30,35,SOFTWARE" // my student info (Req. A)
	};

	// Requirement F2 - create an instance of the Roster class called classRoster
	Roster * classRoster = new Roster();

	// Requirement E2 - create a student object for each student and populate classRosteryArray
	for (int i = 0; i < numStudents; i++) {

		istringstream studentString(studentData[i]);
		string commaSeparatedLine;
		string tempArr[9];

		int j = 0;

		while (getline(studentString, commaSeparatedLine, ',')) {
			tempArr[j] = commaSeparatedLine;
			j++;
		}

		int numDaysInCourse[3] = { stoi(tempArr[5]), stoi(tempArr[6]), stoi(tempArr[7]) };

		DegreeType degree = returnDegreeTypeString(tempArr[8]);

		// Requirement F3 - add each student to classRoster
		classRoster->add(i, tempArr[0], tempArr[1], tempArr[2], tempArr[3], stoi(tempArr[4]), numDaysInCourse, degree);
	}

	// Requirement F4 - complete the rest of the main() function
	classRoster->printAll();

	classRoster->printInvalidEmails();

	// Loop through classRosterArray
	cout << "\nPrinting average # of days per course..." << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printDaysInCourse(classRoster->classRosterArray[i]->getID()); // print average days in course
	}

	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->remove("A3");
	classRoster->remove("A3"); // expected: this line should print an error saying student with this ID not found.

	classRoster->~Roster();

	system("Pause");
};