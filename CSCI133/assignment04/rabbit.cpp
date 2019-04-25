//
//  rabbit.cpp
//  assignment04
//
//  Created by ケビン・ファン on 2/19/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int rabbit(int n, int level = 0);

int main()
{
    rabbit(4);
}

int rabbit(int n, int level)
{
    int intVal;
    cout << "Enter rabbit: n = " << n << endl;
    if(n <= 2)
    {
        cout << "\t";
        intVal = 1;
    }
    else
    {
        cout << "\t";
        intVal = rabbit(n - 1) + rabbit(n - 2);
    }
    cout << "Leave rabbit: n = " << n << " value = " << intVal << endl;
    return intVal;
}