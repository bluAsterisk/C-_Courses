//
//  byte2char.c
//  HW02
//
//  Created by ケビン・ファン on 2/15/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <stdio.h>

int main (void)
{
    auto int    hexVal;
    auto int    result;
    
    do {
        result = scanf("%x", &hexVal);
        if (1 == result)
        {
            printf("%c", hexVal);
        }
    } while (1 == result);
    
    //optional: checked for failed extraction
    if (EOF != result) {
        printf("Invalid data returned");
    }
    return 0;
}