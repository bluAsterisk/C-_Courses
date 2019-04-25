//
//  Week 11.c
//  CSCI 223
//
//  Created by ケビン・ファン on 4/12/16.
//
//

#include <stdio.h>

// Structure Declaration Variants
// ______________________________
// * You can declare variables at the struct declaration:
//  ex:
struct Date
{
    int month;
    int day;
    int year;
} today, tomorrow; // made 2 variables of type Date
// or you can initialize a struct like this:
auto struct Date myDate = {4, 12, 2016};
// * Can also initialize those variables:
// ex:
today, tomorrow = {4, 13, 2016}; // today can be initialized as well
// * If all variables for a structure are defined at the structure declaration,
//   the tag name is optional. (Tag name: Date, in the structure above)
// * Typedefs can be helpful:
typedef struct Date Date;
auto Date myDate;
// or...
typedef
struct Date
{
    int month;
    int day;
    int year;
} Date;