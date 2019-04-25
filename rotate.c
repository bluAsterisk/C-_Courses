//
//  rotate.c
//  HW05
//
//  Created by ケビン・ファン on 2/25/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <stdio.h>


int main()
{
    auto unsigned char userByte;
    auto char   response;
    auto int numRots;
    
    printf("Enter hex byte: ");
    scanf("%hhx", &userByte); // %x would still work too
    printf("Enter number of rotations: "):
    scanf("%d", &numRots);
    printf("L)eft or R)ight? ");
    scanf(" %c", &response); // a space before %c to skip whitespace entered into the input stream, such as \n.
    response = toupper(response);
    for(counter = 1; counter < numRots; counter++)
    {
        if('R' == response)
        {
            userByte = ((userByte & 1) << 7) | (userByte >> 1);
            // checks if LSB is on and rotates it to MSB, then OR it with useByte and rotate right 1.
        }
        else
        {
            userByte = ((userByte & 0x80) >> 7) | (userByte << 1);
            // checks if MSB is on and rotates it to LSB, then OR it with userByte and rotate left 1.
        }
        printf("%4d \t \t %02X \n", counter, userByte);
    }
    return 0;
}