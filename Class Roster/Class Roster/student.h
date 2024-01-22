//
//  student.hpp
//  C867 Class Roster
//
//  Created by Kalvin Saetern on 8/20/23.
//

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
using std::string;
using std::cout;
//using std::edl;

using namespace std;

// Create student class
class Student
{
public:
    
    const static int daysInCourse = 3; //constant array
    
private://accessible to object only
    
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int numDays[daysInCourse];
    DegreeProgram degreeProgram;
    
public://methods
    
    Student();//empty constructor
    Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram);//full constructor
    ~Student();//destructor
    
    //Getter
    string getStudentID();
    string getFristName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getNumDays();
    DegreeProgram getDegreeProgram();//array name and pointer are similar but an array name is always a constant and a pointer is only a constant if seclared as such
    
    //Setter
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setNumDays(int numDays[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    static void printHeader();//displays header for data
    
    void print();//displays "this" student's data
    
    
};

