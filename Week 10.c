//
//  Week 10.c
//  CSCI 223
//
//  Created by ケビン・ファン on 4/5/16.
//
//

#include <stdio.h>

// sscanf/sprintf (p.713)
// ______________________
// Syntax:
int sprintf(char *str, char *format, ...);
int sscanf(char *str, char *format, ...);
//ex:
auto char buf[LEN] = "123"; // say buf[0x210] is stored with '1' '2' '3' 0 (null at end of string)
auto int intVal; // intVal[0x420] gets written with value of 123
sscanf(buf, "%d", &intVal); // this returns 1 for a successful scan
sprintf(buf, "intVal = %d", intVal);
puts(buf); // buf[0x210] now stores 'i' 'n' 't' 'V' 'a' 'l' '  ' '=' ' ' '1' '2' '3' 0

//stdin
// Enter phone num (XXX-XXX-XXXX): 714-992-7385

//main
auto char buf[LEN];
auto int area;
auto int prefix;
auto int suffic;
printf("Enter phone num (XXX-XXX-XXXX): ");
fgets(buf, LEN, stdin);
// buf [0x120] : '7' '1' '4' '-' '9' '9' '2' '-' '7' '3' '8' '5' '\n' 0
if(3 != sscanf(buf, "#3d-%3d-%4d", &area, &prefix, &suffix))
{
    //error...
}


// main
auto char buf[LEN];
auto int int1;
auto int int2;
// get 2 ints from stdin int int1 and int2
SumSting(buf, int1, int2);
puts(buf);

// stdin
// Enter 2 ints: 10 25
// The sum of 10 and 25 is 35.
void SumString(char *str,  int num1, int num2)
{
    sprintf(stf, "The sum of %d and %d is %d", num1, num2, num1 + num2);
    // str that is passed has the base address of the array passed
    // num1 gets value of 10 entered on keyboard
    // num2 gets value of 25 entered on keyboard
}



// typedef Statements (p.746)
// __________________________
// * Used to create a synonym of an existing data type.
// * Syntax: typedef <existing type> <synonym>; ex:
typedef int Counter;
auto Counter myCount;

Couter Foo(counter param);
auto Counter myCounters[LEN];

// orrr you can typedef typedefs!
typedef int Counter;
typedef Counter CounterArray[50];
auto CounterArray myCounters; // this is really an array of 50!
myCounters [0] = 1;



// Pointers to Pointers
// ____________________
//ex:
auto int **ptrPtr;

// main
auto int *myInts;
auto int numElems;
printf("How many ints? ");
scanf("%d", &numElems);
if(AllocInts(&myInts, numElems))
{
    // success! free(myInts) to free array of memory stored
}
else
{
    // failure...
}

int AllocInts(int **ptrPtr, int numElems)
{
    auto int index;
    // ptrPtr => ptr-to-ptr-to-int
    // *ptrPtr => ptr-to-int
    // **ptrPtr => int
    *ptrPtr = malloc(numElems * sizeof(int)); // allocate memory for the pointer to int
    if(NULL == *ptrPtr)
    {
        return FALSE;
    }
    for(index = 0; index < numElems; ++index)
    {
        *(*ptrPtr + index) = index + 1; // dereference of the base address
    }
    return TRUE; // truu
}


// main
auto int int1;
auto int int2;
auto int *ptr;
// get int1 and int2 from stdin...
PointToMax(&int1, &int2, &ptr);
// since the pointer doesn't have an address yet, you pass the address of the pointer

void PointToMax(int *num1, int *num2, int **numPtr)
{
    if(*num1 > *num2)
    {
        *numPtr = num1; // point numPtr to value at num1
    }
    else if(*num1 < *num2)
    {
        *numPtr = num2; // point numPtr to value at num1
    }
    else
        *numPtr = NULL; // if equal, point to null
}



// Command-Line Arguments (p.1091)
// _______________________________
// * You can read additional arguments from the command line when you launch a program.
// ex: ./a.out one two three
// A
int main(int argc, char* argv[])
{
    auto int index;
    for(index = 0; index < argc; ++index)
    {
        puts(argv[index]);
    }
}
// B
int main( int argc, char **argv)
{
    for( ; *argv; ++argv)
    {
        puts(*argv);
    }
}
// * main's parameters:
//  - argc -> "argument count"
//      - number of arguments including the executable
//  - argv -> "argument vector"
//      - an array of pointers to chars
//      - each element points to an argument

// ./a.out 15 10
// 15 + 10 = 25
int man(int argc, char* argv[])
{
    auto int num1;
    auto int num2;
    sscanf(argv[1], "%d", &num1);
    sscanf(argv[2], "%d", &num2);
    printf("%d + %d = %d \n", num1, num2 num1+num2);
    return 0;
}
// enhancements:
// * Check retval of sscanf
// * Check value of argc
if(argc != 3)
{
    puts("usage ,<num1> <num2> ...");
    return 0;
}



// Structures (p.752)
// __________________
// * Can group a variety of data into a single logical type. ex:
struct Date // <- tag name
{
    int month; // structure
    int day;   // members
    int year;  //
}; // structure declaration, doesn't allocate space
auto struct Date myDate;
myDate.month = 4;
myDate.day = 7;
scanf("%d", &myDate.year);
DispDate(myDate);
void DispDate(struct Date *date)
{
    printf("%d/%d/%d \n", (*data).month, date->month, date->year);
    // this arrow operator first dereferences the pointer and gives access to the data.
}


// Bit Fields
// __________
// Assume you need to store this data in a struct:
// * Some flags: f1, f2, f3 -> T/F
// * An int: "type", needs to store values from 1 to 12
// * An int: "index", needs to store values from 0 to 500
struct data
{
    int f1;
    int f2;
    int f3;
    int type;
    int index;
    // 1 struct is 20 bytes
    // If we had an array of 50,000 structs => 1mill bytes!
};
// How many bits for each variable?
//  - flags -> 1 bit for each (3) (simply 1 and 0 for true or false)
//  - type -> 4 bits (since 2^4 = 16, which is enough for 1 to 12)
//  - index -> 9 bits
//      - Total of 16 bits (2 bytes)

auto unsigned short data; // 16 bits
// f1 f2 f3 (   type   )(          index          )
// _______________________________________________
//|  |  |  | 0 | 1 | 1 | 1 |  |  |  |  |  |  |  |  |  |
// * set "type" to 7:
data |= 7 << 9;
// * Use a variable:
data |= n << 9;
// * Make sure n is only 4 bits:
data |= (n & 0xF) << 9;
// * First clear "type" before the OR operation:
data &= 0xE1FF; // group the bits by 4 to figure out a bit mask in hex
// or...
data &= ~(0xF << 9);
// * Can combine operations into one line:
data = (data & ~(0xF << 9)) | ((n & 0xF) << 9);
//      ^ the 2 byte val        ^ 4 bit value shifted left
//       w/ type cleared
// * To extract "type":
type = (data >> 9) & 0xF;

// However, it's not required to do it this way
struct data
{
    int f1:1;
    int f2:1;
    int f3:1;
    int type:4;
    int index:9;
    // doing this is creating bit fields
};
// ex:
auto struct Data    data;
data.type = 7;