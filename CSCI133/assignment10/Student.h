//
//  Student.h
//  assignment10
//
//  Created by ケビン・ファン on 4/8/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef __assignment10__Student__
#define __assignment10__Student__


using namespace std;

class Student
{
public:
    Student();
    Student(string n,
            int i,
            string p,
            int a,
            char g,
            int y,
            double gpa);
    ~Student();
    string GetName();
    void SetName(string n);
    unsigned int GetID();
    void SetID(unsigned int ID);
    unsigned int GetAge();
    void SetPhone(string p);
    string GetPhone();
    void SetAge(unsigned int a);
    char GetGender();
    void SetGender(char g);
    unsigned int GetYear();
    void SetYear(unsigned int y);
    double GetGPA();
    void SetGPA(double d);
    void Print();
private:
    string name;
    unsigned int idNum;
    string phone;
    unsigned int age;
    char gender;
    unsigned int year;
    double GPA;
};

#endif /* defined(__assignment10__Student__) */
