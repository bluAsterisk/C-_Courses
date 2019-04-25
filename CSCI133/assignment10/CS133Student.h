//
//  CS133Student.h
//  assignment10
//
//  Created by ケビン・ファン on 4/15/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef __assignment10__CS133Student__
#define __assignment10__CS133Student__

#include "Student.h"
#include "Date.h"

class CS133Student: public Student
{
public:
    CS133Student();
    CS133Student(string n,
                 int i,
                 string p,
                 int a,
                 char g,
                 int y,
                 double gpa,
                 double s,
                 bool j,
                 unsigned int m,
                 unsigned int d,
                 unsigned int year);
    ~CS133Student();
    void SetScore(double s);
    double GetScore();
    void SetJava(bool j);
    bool GetJava();
    void SetGradDate(unsigned int m,
                     unsigned int d,
                     unsigned int y);
    void GetGradDate();
    virtual void Print();
private:
    double score;
    bool java;
    Date gradDate;
};

#endif /* defined(__assignment10__CS133Student__) */
