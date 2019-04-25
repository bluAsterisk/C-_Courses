//
//  Student.cpp
//  assignment10
//
//  Created by ケビン・ファン on 4/8/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//
#include <iostream>
#include <cstring>
#include "Student.h"

Student::Student()
{
    name = "Name";
    idNum = 0;
    phone = "000-000-0000";
    age = 0;
    gender = 'X';
    year = 0;
    GPA = 0;
}

Student::Student(string n,
        int i = 0,
        string p = "000-000-0000",
        int a = 0,
        char g = 'X',
        int y = 0,
        double gpa = 0)
{
    name = n;
    idNum = i;
    phone = p;
    age = a;
    gender = g;
    year = y;
    GPA = gpa;
}

Student::~Student()
{
    cout << "Calling Student destructor" << endl;
}

string Student::GetName()
{
    return name;
}

void Student::SetName(string n)
{
    name = n;
}

void Student::SetPhone(string p)
{
    phone = p;
}

string Student::GetPhone()
{
    return phone;
}

unsigned int Student::GetID()
{
    return idNum;
}

void Student::SetID(unsigned int ID)
{
    idNum = ID;
}

unsigned int Student::GetAge()
{
    return age;
}

void Student::SetAge(unsigned int a)
{
    age = a;
}

char Student::GetGender()
{
    return gender;
}

void Student::SetGender(char g)
{
    gender = g;
}

unsigned int Student::GetYear()
{
    return year;
}

void Student::SetYear(unsigned int y)
{
    year = y;
}

double Student::GetGPA()
{
    return GPA;
}

void Student::SetGPA(double d)
{
    GPA = d;
}

void Student::Print()
{
    cout << GetName() << " ";
    cout << GetID() << " ";
    cout << GetPhone() << " ";
    cout << GetAge() << " ";
    cout << (char)toupper(GetGender()) << " ";
    switch (GetYear())
    {
        case 1:
            cout << "Freshman ";
            break;
            
        case 2:
            cout << "Sophomore ";
            break;
        
        case 3:
            cout << "Junior ";
            break;
        
        case 4:
            cout << "Senior ";
            break;
            
        default:
            cout << "classStanding ";
            break;
    }
    cout << GetGPA() << endl;
}