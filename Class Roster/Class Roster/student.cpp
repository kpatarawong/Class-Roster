//
//  student.cpp
//  C867 Class Roster
//
//  Created by Kalvin Saetern on 8/20/23.
//
#include "student.h"

Student::Student() //constructor with no parameters
{
    //pointer name -> variable name
    this->studentID = ""; //empty string
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysInCourse; i++) this->numDays[i] = 0;//loops over array and sets default price to 0
    this->degreeProgram = DegreeProgram::Security;//set default degree type to software using value created in Degree.h
}

//Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram)

{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysInCourse; i++) this ->numDays[i] = numDays[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {} //destructor

//Getter
string Student::getStudentID() { return this->studentID; }
string Student::getFristName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getNumDays() { return this->numDays; }//array name is a pointer; return prices individually but to reference them
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Setters; needs incoming parameter
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setNumDays(int numDays[])//set each number of days individually
{
    for (int i = 0; i < daysInCourse; i++) this ->numDays[i] = numDays[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader()//use to print header
{
    cout << "ID" << '\t' << "First" << '\t' << "Last"<< '\t' << "Email" << '\t' << "Age" << '\t' << "Number of Days" << '\t' << "Degree Program" << std::endl <<std::endl;//format of printout
}

void Student::print()
{
    cout << this->getStudentID() << '\t';//tab separated output and getters
    cout << this->getFristName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getNumDays()[0] << ',';//grab days individually instead of pointers
    cout << this->getNumDays()[1] << ',';
    cout << this->getNumDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';//degreeProgram to string; is in an int but uses Degree.h for string
}




