//
//  char2byte.c
//  HW02
//
//  Created by ケビン・ファン on 2/15/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <stdio.h>

int main (void)
{
    auto int inChar;
    auto int counter = 0;
    while((inChar = getchar()) != EOF)
    {
        if (counter >= 20)
        {
            putchar('\n');
            counter = 0;
        }
        printf("%02X", inChar);
        ++counter;
    }
        return 0;
}