//
//  Date.cpp
//  assignment10
//
//  Created by ケビン・ファン on 4/8/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//
#include "Date.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}

Date::Date(unsigned int d,
     unsigned int m,
     unsigned int y)
{
    day = d;
    month = m;
    year = y;
}

Date::Date(const string &mn,
           unsigned int d = 1,
           unsigned int y = 2000)
{
    day = d;
    year = y;
    if(mn == "January")
        month = 1;
    else if(mn == "February")
        month = 2;
    else if(mn == "March")
        month = 3;
    else if(mn == "April")
        month = 4;
    else if(mn == "May")
        month = 5;
    else if(mn == "June")
        month = 6;
    else if(mn == "July")
        month = 7;
    else if(mn == "August")
        month = 8;
    else if(mn == "September")
        month = 9;
    else if(mn == "October")
        month = 10;
    else if(mn == "November")
        month = 11;
    else if(mn == "December")
        month = 12;
    else
        day = 1;
        month = 1;
        year = 2000;
        cout << "Invalid month name: the Date was set to 1/1/2000" << endl;
}

void Date::SetMonth(unsigned int m)
{
    month = m;
}

unsigned int Date::GetMonth()
{
    return month;
}

void Date::SetMonthName(string m)
{
    monthName = m;
}

string Date::GetMonthName()
{
    return monthName;
}

void Date::SetDay(unsigned int d)
{
    day = d;
}

unsigned int Date::GetDay()
{
    return day;
}

void Date::SetYear(unsigned int y)
{
    year = y;
}

unsigned int Date::GetYear()
{
    return year;
}

void Date::printNumeric() const
{
    cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const
{
    switch (month)
    {
        case 1:
            cout << "January";
            break;
        case 2:
            cout << "February";
            break;
        case 3:
            cout << "March";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "June";
            break;
        case 7:
            cout << "July";
            break;
        case 8:
            cout << "August";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "October";
            break;
        case 11:
            cout << "November";
            break;
        case 12:
            cout << "December";
            break;
        default:
            break;
    }
    cout << "/" << day << "/" << year;
}

bool Date::isLeap(unsigned int year) const
{
    if(year % 4 == 0)
    {
        return true;
    }
    else if(year % 100 == 0)
    {
        return false;
    }
    else if(year % 400 == 0)
    {
        return true;
    }
    else
        return false;
}

unsigned int Date::daysPerMonth(unsigned int m,
                                unsigned int y) const
{
    switch (m)
    {
        case 1:
            return 31;
            break;
        case 2:
            if(isLeap(y))
            {
                return 29;
            }
            else
                return 28;
            break;
        case 3:
            return 30;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 30;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 30;
            break;
        case 8:
            return 30;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
        default:
            break;
    }
    return 30;
}

string Date::name(unsigned int m) const
{
    switch (m)
    {
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
        default:
            break;
    }
    return "Month";
}