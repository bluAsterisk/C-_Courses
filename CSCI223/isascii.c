//
//  isascii.c
//  HW04
//
//  Created by ケビン・ファン on 2/22/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <stdio.h>
#define MSB 0x80 // which is 1000 0000

int main (void)
{
    auto int inChar;
    auto int numBytes;
    auto int counter = 0;
    while((inChar = getchar()) != EOF)
    {
        numBytes++;
        //check if its an ASCII character
        if (MSB & inChar)
        {
            printf("NON-ASCII INPUT: %02X detected at offset %#02x \n", inChar, numBytes);
            counter++;
        }
    }
    //display number of non-ASCII characters read
    if(counter > 0)
    {
        printf("A total of %d non-ASCII bytes were encountered. \n", counter);
    }
    else if(counter == 0)
    {
        printf("The input stream was pure ASCII with a total of %d bytes read. \n", numBytes);
    }
    return 0;
}