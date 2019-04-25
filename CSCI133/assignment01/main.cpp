//
//  main.cpp
//  assignment01
//
//  Created by ケビン・ファン on 2/9/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>
#include "triangle.h"


int main()
{
    Triangle tri1(1);
    Triangle tri2(7, '^');
    Triangle tri3(39, 'X', 'O');
    
    tri3.Draw();
    tri3.Summary();
    return 0;
}