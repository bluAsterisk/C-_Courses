//
//  rot13.c
//  HW03
//
//  Created by ケビン・ファン on 2/17/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <stdio.h>


int main(void)
{
    auto int    intVal;
    auto int    charVal;
    
    printf("Please enter a char to be rotated:\n");
    while ((intVal = getchar()) != EOF)
    {
        if(intVal >= 'a' && intVal <= 'z')
        {
            intVal = intVal + 13;
            if (intVal > 'z')
            {
                intVal = intVal - 26;
            }
        }
        else if(intVal >= 'A' && intVal <= 'Z')
        {
            intVal = intVal + 13;
            if(intVal > 'Z')
            {
                intVal = intVal - 26;
            }
        }
        charVal = intVal;
        printf("%c", charVal);
    }
}