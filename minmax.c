//
//  minmax.c
//  CSCI 223
//
//  Created by ケビン・ファン on 2/6/16.
//
//

#include <stdio.h>


int main()
{
    auto int min = 0;
    auto int max = 0;
    auto int intVal = 0;
    auto int result = 0;
    
    //loop that is terminated by EOF
    printf("Please enter integers, EOF to quit... \n");
    do {
        result = scanf("%d", &intVal);
        if(intVal < min)
        {
            min = intVal;
        }
        else if(intVal > max)
        {
            max = intVal;
        }
    } while (result != EOF || result == 0);
    
    printf("Minimum value entered is %d \n", min);
    printf("Maximum value entered is %d\n", max);
    
    return 0;
}