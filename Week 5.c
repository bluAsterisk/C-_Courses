//
//  Week 5.c
//  CSCI 223
//
//  Created by ケビン・ファン on 3/1/16.
//
//

#include <stdio.h>

// Arrays (p.459)
// ______________
// * A contiguous block of variables, all of the same type.
// ex:
auto int myInts[5] = {11 ,22, 33, 44, 55}; // initialization list with initializers inside
// number inside is the dimension (one based value, meaning thats how many it contains)
myInts[3] = 18; // [] is the subscript/index operator, starts at 0
auto int index;
for(index = 0; index < 5; i++)
{
    myInts[index] = 0;
}
intVal = sizeof(myInts); // this gives you the number of bytes, but since this is an array 5 * 4 bytes = 20
int numElems = sizeof(myInts)/sizeof(myInts[0]);// gives 20/4 = 5, this is if you wanted to know the dimension
ZeroElems(myInts, 5); // array identifier and the dimension
// an array without the subscript operator automatically points to the base address which is myInts[0]

void ZeroElems(int array[], int numElems)
{
    auto int index;
    for(index = 0; index < numElems; index++)
    {
        array[index] = 0;
    }
}

// Local Variables(p.198)
// ______________________
// * Are declared inside of a block. They aren't "visibile" outside of the block ("block scope").

// Global Variables
// ________________
// * Are declared outside of any block.
// * Are "visible" from point of declaration to end of file.
// * Are allocated at compile-time from the "data section".
// ex:
int main ()
{
    auto int intVal = 11;
    if(1)
    {
        auto int intVal = 22;
        if(1)
        {
            auto int intVal = 33;
            printf("%d", intVal); // output: 33
        }
        printf("%d", intVal); // output: 22
    }
    printf("%d", intVal);// output: 11
    return 0;
}



// The Runtime Environment
// ________________________
// (Content determined at compile-time)
// Code Section
// Data Section
//  - global variables (if it doesn't get initialized to a value then its default is 0)
//  - static variables

// (Content determined at runtime)
// Stack
//  - auto variables
//  - parameters
// Heap
//  - dynamic memory allocations


// Define vs Declare
// _________________
// * "Define" means a memory address is generated. Memory is consumed.
// * "Declare" notifies the compiler of a symbol
// ex:
auto int myInt; // both a definition and declaration
int Foo(void); // declaration of a function prototype


// Storage Classes
// _______________
// * auto
//  - the default for local variables
//  - automatically allocated and released from the stack
// * extern
//  - allows you to share variables across file boundaries
// ex:

int g_int = 5; // in main.c
void Foo(void);

int main(void)
{
    printf("%d\n", g_int);
    Foo();
    printf("%d\n", g_int);
}

extern int g_int; // this allows the linker to allow changes to the g_int variable defined in main.c

void Foo(void) // in foo.c
{
    g_int = 100;
}



// The "static" Storage Class
// __________________________
// * Allocated at compile-time from the data section.
// * Can be declared in a block
// * Global variables can also be static as well. The symbol will never be made available to the linker.
//   This means that you can't use extern for access in another file for the said static variable.
// * Can also apply to functions, creating "private" functions.
// ex
void Foo(void)
{
    auto    int  autoInt = 0;
    static  int  staticInt = 0;
    printf("%d,%d \n", autoInt, staticInt);
    ++autoInt;
    ++staticInt;
}
int main (void)
{
    Foo(); // output: 0, 0
    Foo(); // output: 0, 1
    Foo(); // output: 0, 2
    // notice the static variable is keeping its value, it isn't overwritten in each call of Foo();
}


// The "register" Storage Class
// ____________________________
// * Suggests to the compiler that a variable be allocated from a CPU register.
//   This allows less work fetching data since the variable has less to travel.
//   However, the compiler may not take that suggestion to allocate the variable from a CPU register.
// * Can't take the address of a register variable (in C, but it works in C++!)
// * If a variable isn't taken in as a register variable then it's taken into the data section as a stack variable.
// ex:
register int counter;


// Header Files
// ____________
// * Use these to #include declarations in source code files.
// * Appropriate items are:
//  - function prototypes
//  - #define statements
//  - class declarations (in C++)
//  - structs
//  - extern variables
//  - typedef statements
// * Use angled brackets ( < > ) for system headers, and double quotes (" ") for custom headers.


// multi-module program
//main.c
#include <stdio.h>
#include "add.h"
#include "sub.h"

int main (void)
{
    auto int int1;
    auto int int2;
    // get two ints from user...
    printf("sum = %d \n", Add(int1, int2));
    printf("sub = %d \n", Sub(int1, int2));
    return 0;
}
//add.c
#include "add.h"
int Add(int val1, int val2)
{
    return val2 + val2;
}
//sub.c
#include "sub.h" //this is just to be safe from warnings
int Sub(int val1, int val2)
{
    return val1 - val2;
}
//add.h
int Add(int val1, int val2);
//sub.h
int Sub(int val1, int val2);

// To Build: -c creates an object file, without this it s probably deleted after creating an executable.
// gcc -c main.c => main.o
// gcc -c add.c => add.o
// gcc -c sub.c => sub.o
// gcc main.o add.o sub.o => a.out
