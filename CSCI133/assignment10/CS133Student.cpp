//
//  CS133Student.cpp
//  assignment10
//
//  Created by ケビン・ファン on 4/15/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//
#include <iostream>
#include "CS133Student.h"

CS133Student::CS133Student()
{
    SetName("Name");
    SetID(0);
    SetPhone("000-000-0000");
    SetAge(0);
    SetGender('X');
    SetYear(0);
    SetGPA(0);
    SetScore(0);
    SetJava(false);
    SetGradDate(1, 1, 2000);
}

CS133Student::CS133Student(string n,
                           int i = 0,
                           string p = "000-000-0000",
                           int a = 0,
                           char g = 'X',
                           int y = 0,
                           double gpa = 0,
                           double s = 0,
                           bool j = false,
                           unsigned int m = 1,
                           unsigned int d = 1,
                           unsigned int year = 2000): Student(n, i, p, a, g, y, gpa)
{
    SetName(n);
    SetID(i);
    SetPhone(p);
    SetAge(a);
    SetGender(g);
    SetYear(y);
    SetGPA(gpa);
    SetScore(s);
    SetJava(j);
    SetGradDate(m, d, year);
}

CS133Student::~CS133Student()
{
    cout << "Calling CS133Student destructor" << endl;
}

void CS133Student::SetScore(double s)
{
    score = s;
}

double CS133Student::GetScore()
{
    return score;
}


void CS133Student::SetJava(bool j)
{
    java = j;
}

bool CS133Student::GetJava()
{
    return java;
}

void CS133Student::SetGradDate(unsigned int m,
                               unsigned int d,
                               unsigned int y)
{
    gradDate.SetMonth(m);
    gradDate.SetDay(d);
    gradDate.SetYear(y);
}

void CS133Student::GetGradDate()
{
    gradDate.printNumeric();
}
void CS133Student::Print()
{
    cout << Student::GetName() << " ";
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
    cout << GetGPA() << " ";
    cout << score << " ";
    if(GetJava())
        cout << "yes ";
    else
        cout << "no ";
    GetGradDate();
    cout << endl;
}