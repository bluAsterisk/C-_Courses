//
//  Date.h
//  assignment10
//
//  Created by ケビン・ファン on 4/8/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef __assignment10__Date__
#define __assignment10__Date__
#include <string>
using namespace std;

class Date
{
public:
    Date();
    Date(unsigned int day,
         unsigned int month,
         unsigned int year);
    Date(const string &mn,
         unsigned int d,
         unsigned int y);
    void SetDay(unsigned int d);
    unsigned int GetDay();
    void SetMonth(unsigned int m);
    unsigned int GetMonth();
    void SetMonthName(string m);
    string GetMonthName();
    void SetYear(unsigned int y);
    unsigned int GetYear();
    void printNumeric() const;
    void printAlpha() const;
private:
    unsigned int day;
    unsigned int month;
    string monthName;
    unsigned int year;
    bool isLeap(unsigned int year) const;
    unsigned int daysPerMonth(unsigned int m,
                              unsigned int y) const;
    string name(unsigned int m) const;
};
#endif /* defined(__assignment10__Date__) */
