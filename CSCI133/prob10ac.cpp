//
//  prob10ac.cpp
//  assignment04
//
//  Created by ケビン・ファン on 2/19/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

void writeLine(char fill, unsigned int width);
void writeBlock(char fill, unsigned int width, unsigned int row);

/*int main()
{
    cout << "Calling writeLine function " << endl;
    writeLine('*', 5);
    cout << endl;
    cout << "Calling writeBlock function " << endl;
    writeBlock('*', 5, 3);
    cout << endl;
}*/

void writeLine(char fill, unsigned int width)
{
    cout << fill;
    width--;
    if(0 != width)
    {
        writeLine(fill, width);
    }
}

void writeBlock(char fill, unsigned int width,unsigned int row)
{
    if(row > 0)
    {
        int temp = width;
        writeLine(fill, width);
        width = temp;
        row--;
        cout << endl;
        writeBlock(fill, width, row);
    }
}