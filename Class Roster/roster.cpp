//
//  roster.cpp
//  C867 Class Roster
//
//  Created by Kalvin Saetern on 8/20/23.
//

#include <string>
#include "roster.h"

void Roster::parse(string studentdata)//parses each row
{
    DegreeProgram degreeProgram = Security; //default value
    if (studentdata.back() == 'K') degreeProgram = Network;
    else if (studentdata.back() == 'E') degreeProgram = Software;
    
    int rhs = studentdata.find(",");//find comma
    string studentID = studentdata.substr(0, rhs);//extract substring in front of comma
    
    int lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string firstName = studentdata.substr(lhs, rhs - lhs);//first name
             
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string lastName = studentdata.substr(lhs, rhs - lhs);//last name
             
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string email = studentdata.substr(lhs, rhs - lhs);//Email
             
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int age = stoi(studentdata.substr(lhs, rhs - lhs));//age
            
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d1 = stoi(studentdata.substr(lhs, rhs - lhs));//First number of days
             
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d2 = stoi(studentdata.substr(lhs, rhs - lhs));
             
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int d3 = stoi(studentdata.substr(lhs, rhs - lhs));
             
    
    add(studentID, firstName, lastName, email, age, d1, d2, d3, degreeProgram); //add student object
}
             
//Add method combines strings and creates object in repo
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int d1, int d2, int d3, DegreeProgram degreeProgram)
    {
        //days back into aan array for construtor
        int darr[3] = {d1, d2, d3};
        //make new student object; first index -1
        classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, darr, degreeProgram);//Full constructor
    }
    
    //display all students using tab delimited output
    void Roster::printAll()
    
    {
        Student::printHeader();
        for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
        
    }
    
    void Roster::printInvalidEmails()
             
             {
        bool any = false;
        //assume no invalid emails
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            string email = (classRosterArray[i]->getEmail());
            //create variable to shorten statement below
            if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
                
            {
                any = true;
                //any reassigned true if if-statement ment
                cout << email << ":" << classRosterArray[i]->getFristName() << std::endl;
                //prints invalid email
            }
            
        }
        if (!any) cout << "NONE" << std::endl;
        //prints if no invalid IDs
        }
             
    
    void Roster::PrintAverageDays(string studentID)
    {
        
        for (int i = 0; i <= Roster::lastIndex; i++)
        {
            if (classRosterArray[i]->getStudentID()==studentID)
            {
                cout << studentID << ":";
                cout << (classRosterArray[i]->getNumDays()[0]+
                         classRosterArray[i]->getNumDays()[1]+
                         classRosterArray[i]->getNumDays()[2])/3 << std::endl;
                //divide by number of course day counts
            }
        }
    }
     
    //display students matching degree type
    void Roster::printByDegreeProgram(DegreeProgram dt)
             {
        Student::printHeader();
        for (int i = 0; i <= Roster::lastIndex; i++) {
            if (Roster::classRosterArray[i]->getDegreeProgram() == dt) classRosterArray[i]->print();
        }
        cout << std::endl;
    }
    
    bool Roster::removeStudentByID(string studentID)
    //takes student id for student to be removed as param
             {
        bool success = false; //assume student does not exist
        for (int i=0; i <= Roster::lastIndex; i++)
            //use lastIndex since index may change
        {
            if (classRosterArray[i]->getStudentID() == studentID)
            {
                success = true;//found student
                if (i < studentDataTable - 1)
                {
                    Student* temp = classRosterArray[i];//swaps places with last student
                    classRosterArray[i] = classRosterArray[studentDataTable - 1];//moves pointer not data in memory
                    classRosterArray[studentDataTable - 1] = temp;
                }
                Roster::lastIndex--;//last student is hidden but not destroyed
            }
        }
        if (success)
        {
            cout << studentID << " removed from roster." << std::endl << std::endl;
            this->printAll();//display all students expt removed students
        }
        else cout << studentID << " not found." << std::endl << std::endl;
        return 0;
    }

Roster::~Roster()//destructor
{
    cout << "Destructor called!" << std::endl << std::endl;
    for (int i=0; i < studentDataTable; i++)
        //size of numBooks stays the same unlike lastIndex
    {
        cout << "Removing student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
        //set to nullptr so it is no longer pointed at that address otherwise could crash
    }
}
             
             
        
    
             

