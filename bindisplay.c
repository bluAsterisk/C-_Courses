//
//  bindisplay.c
//  HW06
//
//  Created by ケビン・ファン on 2/29/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void binDisplay(char binVal[]);

int main()
{
    /*
    int result;
    int intVal;
    char binStr[8];
    do {
        printf("Enter an integer value: ");
        result = scanf("%d", &intVal);
        sprintf(binStr, "%02X", intVal);
        binDisplay(binStr);
    } while (0 != result);
     */
    auto unsigned int userInt;
    auto int numBitsLeft = sizeof(int) * 8 - 1;
    auto int result;
    
    printf("Enter an int: ");
    result = scanf("%d", &userInt);
    if(EOF == result)
    {
        puts("Adieu!");
        return 0;
    }
    else if(1 != result)
    {
        // error, exit...
    }
    while (numBitsLeft >= 0)
    {
        printf("%d", (userInt >> numBitsLeft) & 1);
        // this loops from the MSB until you get to 0x01
        if((numBitsLeft & 3) == 0) // if the bits end with 00 (not 4), then it separates with a space.
        {
            putchar(' ');
        }
        --numBitsLeft;
    }
    return 0;
}

// gcc --std = c99 foo.c (allows for loops when compiling)
// copying in jmacs:
// set mark: ctrl + spacebar
// copy: alt + w
// cut: ctrl + w
// paste: ctrl + y

void binDisplay(char binVal[])
{
    for (unsigned int i = 0; i < strlen(binVal); i++)
    {
        switch (binVal[i])
        {
            case 'F':
                printf("1111 ");
                break;
                
            case 'E':
                printf("1110 ");
                break;
                
            case 'D':
                printf("1101 ");
                break;
                
            case 'C':
                printf("1100 ");
                break;
                
            case 'B':
                printf("1101 ");
                break;
                
            case 'A':
                printf("1010 ");
                break;
                
            case '9':
                printf("1001 ");
                break;
                
            case '8':
                printf("1000 ");
                break;
                
            case '7':
                printf("0111 ");
                break;
                
            case '6':
                printf("0110 ");
                break;
                
            case '5':
                printf("0101 ");
                break;
                
            case '4':
                printf("0100 ");
                break;
                
            case '3':
                printf("0011 ");
                break;
                
            case '2':
                printf("0010 ");
                break;
                
            case '1':
                printf("0001 ");
                break;
                
            case '0':
                printf("0000 ");
                break;
                
            default:
                break;
        }
    }
}