//
//  EmployeeInfo.h
//  assignment12
//
//  Created by ケビン・ファン on 5/1/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef __assignment12__EmployeeInfo__
#define __assignment12__EmployeeInfo__
#include <iostream>
using namespace std;


class EmployeeInfo
{
public:
    EmployeeInfo();
    EmployeeInfo(string, int);
    void SetName(string);
    string GetName();
    void SetID(int);
    int GetID();
    bool operator <(const EmployeeInfo testLess);
    bool operator >(const EmployeeInfo testLess);
    bool operator ==(const EmployeeInfo testLess);
private:
    string name;
    int ID;
};


#endif /* defined(__assignment12__EmployeeInfo__) */
