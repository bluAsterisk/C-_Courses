//
//  Week 2.c
//  CSCI 223
//
//  Created by ケビン・ファン on 2/9/16.
//
//

#include <stdio.h>
#include <cstdlib>
#include <ctype.h>

// Assignment Statements (p.104)
//_______________________________
// Syntax: <lvalue> = <rvalue>;
// * The assignment operator evaluates to the value being assigned. ex:
printf("%d", myInt = 65);    // output: 65
// First the rvalue is evaluated, then the result is copied to the lvalue. ex:
myInt = 25;
myInt = 20+10;
myInt = myInt + 100;
// "Shorthand" Version: <lvalue> <operator> = <rvalue>; ex:
myint += 100;

//  foo.c
//__________________
int main(void)
{
    int int1 = 1;
    int int2 = 2;
    int int3 = 3;
    
    int2 = int2 = int3;
    //all are set to value of int3
}



// Functions
//________________________________
#include <stdio.h>

int AddInts (int op1, int op2); // function prototype (needs the semicolon)
int main (void)
{
    auto int    int1;
    auto int    int2;
    auto int    sum;
    // get int1 and int2 from user.
    sum = AddInts(int1, int2); // parenthesis are the function call identifier, inside goes the arguments.
    // display sum.
    return 0;
}

// heading + block of code is the function implementation (or definition)
// v v v first line is the function heading
int AddInts (int op1, int op2) // inside the parenthesis are the formal parameters
{
    auto int    total;
    total = op1 + opt2;
    return total;
}
// Note:
// * When a function begins execution, space is allocated for its parameters and local variables.
//   When the function returns that space is released.
// * Parameters are always initialized by their corresponding arguments.




// Stack Frame
//________________________________
// A data structure that contains:
//  - arguments for a function
//  - return address (RA) in memory
//  - current value of base pointer (BP) register. BP points to the current stack frame.
//  - local variables

// Processor Registers
// * SP: Stack pointer - temporary data
// * IP: Instruction Pointer - points to next instruction
// * BP: Base Pointer - points to current stack frame

int main(void)
{
    auto int    a = 2;
    auto int    b = 5;
    
    
    Foo(a, b); // in C, the " calling convention" pushes arguments (args) on stack in reverse order
}

void Foo(int c, int d)
{
    auto int    x = 10;
    auto int    y = 14
    // then addresses are changed in assembly language
    c = 7; // mov[bp + 8], 7
    x = 58; // mov[bp - 4], 58
}

// How Foo returns to main:
//_________________________________
// * Restore IP: mov ip, [bp + 4]
// * Restore BP: move bp, [bp]
// * Restore SP: add sp, 24



// Indentifiers (p.36)
//_________________________________
// * The first character must be a letter from a - z or an underscore.
// * All other chars must be letters, underscores, or digits.
// * Cannot be a reserved word.



// Integers (p.40)
//_________________________________
// * Different sizes:
//      - short (at least 2 bytes) up to 16 bits, gives 2^16 patterns <= int <= long <= long long
// * Can be signed (positive or negative) or unsigned (positive only)
//   ____________________________________________
//   | 1 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 0 |
//     ^___ (sign bit)
//   ex: A char has 8 bits, so 2^8 -> unique patterns.
//      0__________unsigned-----------255
//     -128__________signed___________127
// note: if you use unsigned for your variable then the int will never be negative
//       therefore the compiler knows that the variable will not be negative even
//       if you assign it to a negative number.



// Literal Constants
//_________________________________
// - default is base ten
// - prefixes:
//   -- 0x for hex (base ten), ex: 0x123
//   -- 0 for octal ( base 16), ex: 0123
// - suffixes:
//   -- u or U -> unsigned, ex: 12u
//   -- l or L -> long, ex: 12L
//   -- ll or LL -> long long, ex: 12LL



// Reals (Floating-Point) (p.41)
//__________________________________
// * float <= double <= long double
//    ^- (4 bytes) ^- (8 bytes) ^- (12 bytes)
// * Suffixes for literals
//   - default is a double: 12.2
//   - f or F for float: 14.2f
//   - l or L for long double: 14.2L
// ____________| printf | scanf |_____
// float_______|   %f   |  %f   |_____
// double______|   %f   |  %lf  |_____
// long double |   %Lf  |  %Lf  |
// -----------------------------------



// Characters (p.39)
//__________________________________
// * A char is really just a one-byte int. ex:
printf("Enter a char:");
scanf("%c", &myChar); // &myChar is the address of the ASCII value
myChar = 'a'; // 'a' is a character constant
// * convert a digit char to the int it represents, ex:
result = myDigit - '0'; // this will take the variable's int value and subtract it by '0', which is 48
// * convert case:
upper = (lower - 'a') + 'A';
lower = (upper - 'A') + 'a';



// Character I/O
//__________________________________
// * getchar() (returns an int)
//   - reads a single char form the stdin (including whitespace)and returns it to caller.
//   - line-buffered (waits for newline), ex:
auto int    charVal;
charVal = getchar();
//   - if EOF is read, it returns EOF (which is an int = -1).
// * putchar()
//   - writes a single char to stdout
// * puts() (put string)
//   - works like printf without the flags



// Predefined Character Functions (p.1062)
//________________________________________
// * #include <ctype.h>
//   - isalpha, isdigit, isupper, etc
//   - return zero or nonzero, ex:
if(isalpha(charVal))
{
    // alphabetic character detected
}
//   - toupper, tolower
//      -- returns a converted value, doesn't change the given argument. ex:
response = toupper(response);



// Redirection Operators (used in bash)
//_____________________________________
// * used on the command line:
//   - 1) <
//     -- attaches stdin to an external file; the file must exist.
//        ex: ./a.out <data.txt
//   - 2) >
//     -- attaches stdout to an external file; file is initially empty.
//        ex: ./a.out >results.txt
//   - 3) >>
//     -- just like #2, except file is opened in "append" mode. It adds to the said file.
//        ex: ./a.out >> results.txt
// STDIN -----------> a.out -----------> STDOUT
//   ^--- attached to keyboard by default  ^--- attached to monitor by default
int main(void)
{
    auto int    charVal;
    while ((EOF != (charVal = getchar()))
    {
        putchar(charVal);
    }
    return 0;
}
// using this program we can write , copy, and overwrite files.