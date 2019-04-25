//
//  triangle.cpp
//  assignment01
//
//  Created by ケビン・ファン on 2/4/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include "triangle.h"
#include <iostream>
using namespace std;

//member functions
int Triangle::GetSize()
{
    return width;
}

int Triangle::Perimeter()
{
    int perimeter = width * 3;
    return perimeter;
}

double Triangle::Area()
{
    double area = ((width * width) / 2);
    return area;
}

void Triangle::Grow()
{
    if (width >= 1 || width < 39)
    {
        width++;
    }
}

void Triangle::Shrink()
{
    if (width >= 1 || width < 39)
    {
        width--;
    }
}

void Triangle::SetBorder(char bord)
{
    border = bord;
}

void Triangle::SetFill(char fill)
{
    filler = fill;
}

void Triangle::Draw()
{
    //int whtSp = width / 2;
    int iW = 0;
    int iF = 0;
    int row;
    for (row = 1; row <= width; row++)
    {
        iW = width - row;
        for (int i = 1; i < iW; i++)
        {
            cout << " ";
        }
        if (row == 2)
        {
            cout << border << " ";
        }
        else if ((row < width) && (row >= 3))
        {
            iF = row - 2;
            cout << border << " ";
            for (int i = 1; i <= iF; i++)
            {
                cout << filler << " ";
            }
        }
        else if (row == width)
        {
            for (int i = 1; i < width; i++)
            {
                cout << border << " ";
            }
        }
        cout << border << endl;
    }
}

void Triangle::Summary()
{
    cout << "Here's a summary of the triangle: " << endl;
    cout << "The size of a side on the triangle is " << width << " units." << endl;
    cout << "The perimeter of the triangle is " << Perimeter() << " units." << endl;
    cout << "The area of the triangle is " << Area() << " units." << endl;
    cout << "This triangle looks like " << endl;
    Draw();
}