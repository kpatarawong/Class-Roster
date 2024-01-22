//
//  roster.hpp
//  C867 Class Roster
//
//  Created by Kalvin Saetern on 8/20/23.
//

#pragma once
#include "student.h"
#include <stdio.h>

class Roster
{
public:
    int lastIndex = -1;
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable]; //not declared dynamically
    
public:
    //Parse method goes through a set of comma delimetted strings and extract data
    void parse(string row);
    //pulls student data and creates struent object in roster
    void add(string studentID, string firstName, string lastName, string email, int age, int d1, int d2, int d3,
            DegreeProgram degreeProgram);
    //once student object created, call funtions on it
    void printAll();//calls print()
    void printByDegreeProgram(DegreeProgram dt);//Degree Program passed in, print by degree program
    void printInvalidEmails();//a valid email should includ an at sign ('@'), a period ('.'), and should not include space (' ').
    void PrintAverageDays(string studentID);//print average days for each class
    bool removeStudentByID(string studentID);//find student and remove
    ~Roster();//destructor
    
};
