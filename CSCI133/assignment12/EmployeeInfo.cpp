//
//  EmployeeInfo.cpp
//  assignment12
//
//  Created by ケビン・ファン on 5/1/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include "EmployeeInfo.h"

EmployeeInfo::EmployeeInfo()
{
    name = "No name";
    ID = 0000;
}

EmployeeInfo::EmployeeInfo(string n, int i)
{
    name = n;
}

void EmployeeInfo::SetName(string n)
{
    name = n;
}

string EmployeeInfo::GetName()
{
    return name;
}

void EmployeeInfo::SetID(int i)
{
    ID = i;
}

int EmployeeInfo::GetID()
{
    return ID;
}

bool EmployeeInfo::operator <(const EmployeeInfo testLess)
{
    if(ID < testLess.ID)
        return true;
    else
        return false;
}

bool EmployeeInfo::operator >(const EmployeeInfo testLess)
{
    if(ID > testLess.ID)
        return true;
    else
        return false;
}

bool EmployeeInfo::operator ==(const EmployeeInfo testLess)
{
    if(ID == testLess.ID)
        return true;
    else
        return false;
}