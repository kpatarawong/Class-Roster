//
//  main.cpp
//  C867 Class Roster
//
//  Created by Kalvin Saetern on 8/20/23.
//

#include <iostream>
#include "roster.h"
#include <string>
#include <array>
using namespace std;
//using std::endl;

int main() {
    
    cout << "Student Name: Kalvin Saetern" << endl;
    cout << "Student ID: 009931191" << endl;
    cout << "Course Title: C867 - Scripting and Programming - Application" << endl;
    cout << " " << endl;
    cout << " " << endl;

    // Modified studentData table
    const string studentData[] ={
        "A1,John,Smith,John1989@gm ail.com,20, 30, 35, 40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kalvin,Saetern,ksaete3@wgu.edu,35,15,20,25,SOFTWARE" };
    
    const int studentDataTable = 5;//set array size
    Roster roster;//creates repo using default parameterless constructor; everthing set to 0
    
    for (int i = 0; i < studentDataTable; i++) roster.parse(studentData[i]);
   
    cout << "Displaying all students:" << std::endl;
    roster.printAll();
    cout << std::endl;
    // display all students
    
    
    cout << "Displaying invalid email address:" << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;
    //display all students with incorrectly formatted email address
    
    cout << "Displaying average days per class:" << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        roster.PrintAverageDays(roster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;
    //average number of days each student spend in 3 classes
    
    cout << "Displaying all software students:" << std::endl;
    roster.printByDegreeProgram(Software);
    cout << std::endl;
    //display students in the software degree program
    
    cout << "Romove student A3." << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl;
    //remove student A3 and print all remaing students
    
    cout << "Remove A3 agin" << std::endl <<std::endl;
    roster.removeStudentByID("The student with the ID: A3 was");
    cout << std::endl << std::endl;
    //remove error when A3 not found
    
    
    
    
}
