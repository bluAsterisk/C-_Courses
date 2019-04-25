//
//  Week 14.c
//  CSCI 223
//
//  Created by ケビン・ファン on 5/3/16.
//
//

#include <stdio.h>

// The Right/Left Rule (p.1125)
// ____________________________
// * Some scenarios:
//      1) Need to declare an array of 10 pointers to functions
//         that return a pointer to an int.
//      2) Need a pointer to a fuction that returns a pointer to
//         to a 3x4 array of doubles.
// * The C compiler understands certain attributes:
//      Attribute                   Meaning
//          ()              "function that returns..."
//          [n]             "an array of n..."
//          *               "pointer to..."
// Attributes can be combined:
// *() -> function that returns a pointer
// (*)() -> pointer to a function
// *[] -> array of pointers
// (*)[] -> pointer to array
// [][] -> array of arrays
// ** -> pointer to pointer
// Note: You must use an intervening set of parentheses between
//       the function and array attributes
//      Not allowed:
//      ()[] -> function returning array
//      []() -> array of functions

// Using the R/L Rule
// __________________
// - Begin with identifier
// - Look right for attribute; if found, translate.
// - Look left of identifier, if attribute found, translate
// - Continue outward, looking R and L,
//   translating until you reach the data type.
// ex:
// A)
unsigned long myLongs[10]; // myLongs is an array of 10 unsigned longs
// B)
unsigned long *p[5]; // p is an unsigned pointer to 5 unsigned longs
// C)
int (*pf)[5])(); // pf is an array of 5 pointers to functions returning int
// #1
int* *pf[10](); // pf is an array of 10 pointers to functions returning pointer to an int
// #2
double (*(*pf)())[3][4];
int (*signal(int sig, int (*pf)()))();
int *(*(*(*x)())[])();



// Binary File I/O (p.823)
// _______________________
// * Use functions for block I/O:
size_t fread(void *buffer, size_t size, size_t count, FILE *stream);
// (pointer to buffer, number of bytes in one record, number of records to read, file to be read)
size_t fwrite(const void *buffer, size_t size, size_t count, FILE *stream);


// Random Access
// _____________
int fseek(FILE *stream, long offset, int origin);
// offset relative to origin ---^
// defined constants for origin: -----------^
// SEEK_CURR - current position
// SEEK_END - end of file (negative offset)
// SEEK_SET - beginning of file
long ftell(FILE *stream);
// returns the offset relative to the beginning of file
void rewind (FILE *stream);
// sets current position to beginning of file


typedef struct
{
    char name[LEN];
    int SSN;
    double balance;
} AcctInfo;
// Note Assume one record is 100 bytes...

// data.dat
//    [0]        [1]        [2]       [3]
//____________________________________________
//| AcctInfo | AcctInfo | AcctInfo | AcctInfo |
//|0  --  99 |100 -- 199|200 -- 299|300 -- 399|

// main
auto AcctInfo info;
fptr = fopen("data.dat", "a+");
// get values into the "info" variable
// write record to file
if(1 != fwrite(&info, sizeof(info), 1, fptr))
{
    // error...
}
// get a target record number from the user...
// position to the target record
if(0 != fseek(fpt, recordNum * sizeof(info), SEEK_SET))
{
    // error...
}
else if(1 != fread(&info, sizeof(info), 1, fptr))
{
    // error...
}
else
// use printf to display info's members...


// The Preprocessor (p.1071)
// _________________________
// * Macros
//  - use the #define directive. ex:
#define INTVAL 10
auto int result;
result = 25 + INTVAL;
// To see expanded macro, use the -E switch.
// ex: gcc -E foo.c > foo.i
// or gcc -E | less (| connects stdout of the command to stdin of the other command.)
// using redirection to an intermediate file lets you see what the compiler sees
#define IS_LEAP_YEAR (0 == year % 4) && (0 != %100) \ // "\" is a macro continuation character
                    || (0 == year % 400)
int main (void)
{
    auto int year;
    printf("Enter year: ");
    scanf("%d", &year);
    if(IS_LEAP_YEAR)
        puts("Leap year!");
    else
        puts("Not a leap year...");
}

// or if you want to give it an argument, put () in front of the macro
#define IS_LEAP_YEAR(yr) (0 == yr % 4) && (0 != %100) \ // "\" is a macro continuation character
                            || (0 == yr % 400)
// works kinda like a function
int main (void)
{
    auto int year;
    printf("Enter year: ");
    scanf("%d", &year);
    if(IS_LEAP_YEAR(year))
        puts("Leap year!");
    else
        puts("Not a leap year...");
}

#define SQUARE(val) val * val
printf("%d\n", SQUARE(14));
printf("%f\n", SQUARE(5.14));
printf("%f\n", SQUARE(3 + 1)); // this would give 7 because 3 + 1 * 3 + 1 = 7 (use parenthesis in macro)

#define MAX(a, b) (a) > (b) ? (a) : (b)
maxVal = MAX(int1, int2);

#define ISLOWER(x) ((x) >= 'a') && ((x) <= 'z')


// Stringizing Operator (#)
// ________________________
// * Converts a macro parameter to a string literal. ex:
#define WARN_IF(expr) \
        if(expr) \
        {
            fprintf(stderr, "Warning: " #expr "\n"); \
        }
scanf("%d", &userInt);
WARN_IF(userInt == 0);
// the userInt == 0 will be printed on the fprintf line in place of #expr



// The Token Pasting Operator (##)
// __________________________
// * Aka, the "token-merging" operator
// * Used to merge/paste two tokens to form a new token.
// * Token doesn't have to be a macro parameter
typedef struct
{
    char *name;
    void (*fptr)(void);
} MenuItem;
// ver. 1
auto MenuItem menu[] =
{
    {"Add", HandleAdd},
    {"Update", HandleUpdate},
    {"Print", HandlePrint},
    {"Quit", HandleQuit}
};
#define MENU_ITEM(item) \
        {#item, Handle ## item}

// ver 2
auto MenuItem menu[] =
{
    {MENU_ITEM(Add)},
    {MENU_ITEM(Update)},
    {MENU_ITEM(Print)},
    {MENU_ITEM(Quit)}
};
