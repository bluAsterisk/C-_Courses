//
//  triangle.h
//  assignment01
//
//  Created by ケビン・ファン on 2/4/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef __assignment01__triangle__
#define __assignment01__triangle__

#include <iostream>
#include <cstdlib> // for atoi

class Triangle
{
public:
    
    //default constructor
    Triangle()
    {
        width = 1;
        border = '#';
        filler = '*';
    }
    
    //constructor with given parameters of size, border, and filler
    Triangle(int size, char bord, char fill)
    {
        width = size;
        border = bord;
        filler = fill;
        
        //if (atoi(border) < 33 || atoi(border) > 126)
        //{
        //    cout << "That's an invalid border" << endl;
        //}
        
        //else if (atoi(filler) < 33 || atoi(filler) > 126)
        //{
        //    cout << "That's an invalid filler" << endl;
        //}
    }
    
    //constructor given only size and border
    Triangle(int size, char bord)
    {
        width = size;
        border = bord;
        
        //if (atoi(border) < 33 || atoi(border) > 126)
        //{
        //    cout << "That's an invalid border" << endl;
        //}
    }
    
    ///constructor given only size
    Triangle(int size)
    {
        width = size;
    }
    
    //member functions
    int GetSize();
    int Perimeter();
    double Area();
    void Grow();
    void Shrink();
    void SetBorder(char bord);
    void SetFill(char fill);
    void Draw();
    void Summary();
    
    
private:
    int width;
    char border;
    char filler;

};


#endif /* defined(__assignment01__triangle__) */
