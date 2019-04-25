//
//  Week 1.c
//  CSCI 223
//
//  Created by ケビン・ファン on 2/2/16.
//
//

//History of C
//Algol -> BCPL -> B (Ken Thompson) -> C (Dennis Ritchie)

//foo.c (for C file)
//main()
//{
//    printf("Hello world");
//}
//Will give warnings:
//-- return type defaults to 'int'
//-- implicit declaration of 'printf'
//-- control reaches end of non-void function

//foo.c (correct build)
#include <stdio.h> //for standard IO
int main(void)
{
    printf("Hello world\n");
    return 0;
}

//enter gcc foo.c => a.out (uses gcc for c files)

//[BUILD PROCESS]
//This code needs to go through a preprocessor for the printf function

//foo.i (intermediate file)
//starts at <stdio.h> because of the #
//then executes the rest of the code from main to return 0;

//foo.i goes through the C compiler
//foo.o ("Object File")
//gets converted to binary
//the "unresolved externals is put at the bottom of the binary for the printf function

//object file gets sent to the Linker that links the standard library in binary (address for printf)

//linker then sends the code to a.out (the executable)

//To run: ./a.out



//Example
int main(void)
{
    auto int op1; //auto means automatically allocated and released for the variable
    auto int op2; //auto is also the automatic storage class, this is to be clear
    auto int sum;
    op1 = 25;
    op2 = 75;
    sum = op1 + op2;
    printf("%d +%d = %d\n", op1, op2, sum);
    //%d means integer
    return 0; // end main function
}
//STDOUT (standard output)
//________________________
//|25 + 75 = 100
//|
//|
//|



//The printf Function (p.54)
//__________________________
//* Performs a binary to text conversion
// (binary data) -> printf -> text stream (stdout)
//* Returns an int, the # of chars written to stdout.


//Syntax for printf conversion specifier (p.56)
//_____________________________________________
//_________________________________________________________________________
//| %  (required) | flag | min. width | Precision | Size | Code (required) |
//        #1         #2        #3          #4         #5           #6

// #6: Code
// - character: c
// - string: s
// - float/double: f
// - integer:
//    - base 10: d or i
//    - base 16: x or X
//    - base 8: o

// #3: Min Width
// - Used to reserve space for field widths. (like cout << setw(6) << 12 << endl;)
// for example:
printf("|%d|\n", 5);              // output: |5|
printf("|%5d|\n", 5);             // output: |     5| (that 5 will allocate space to display)
printf("|%5d|\n", -5);            // output: |     -5|
printf("|%*d|\n", 5, -5);         // output: |     -5| (the first 5 will be used inplace of *)
printf("|%*d|\n", CalcWidth(), -5);// output: |     -5| (the CalcWidth function will be used inplace of *)

// #4: Precision
// - Used to limit the number of digits of precision
// - Always begins with a decimal point
// for example:
printf("|%.2f|\n", 12.34567);     // output: |12.35| (f is for float. Also since it was cut to 2 decimals, it will round up)
printf("|%*8.2f|\n", 12.34567);   // output: |   12.35| (3 spaces are left over from 8 characters to display)
printf("|%*2.2f|\n", 12.34567);   // output: |12.35| (Even though it was more than what was allocated the rest spills over)
// Note: You can use an asterisk to provide a runtime argument.
// * If used with hex or octal, precision indicates number digits to display. ex:
       printf("|%.5x|\n", 0x abc); //output: |00abc|
// * Can also limit number of chars in a string, ex:
       printf("%.5\n", "abcdefghijk"); // output: abcde

// #5: Size
// * Used to support different types of ints and floats
//  - ints:
//      -- h -> short int -> %hd
//      -- l -> long int -> %ld
//      -- ll -> long long int -> %lld
//  - floats:
//      --L -> long double -> %Lf

// #2: Flag
// * May consist of one or more of these:
//  -- '#' -> "alternate form", automatically prefixes a leading 0 for octals or 0x for hex values. ex:
       printf("0x%x", 0xfe); // or
       printf("%#x", 0xfe);
//  -- '-' -> left-justify in a field width.
//  -- ' ' -> prefix a space if value is a signed positive.
//  -- '+' -> prefix a plus sign if the value is a signed positive.
//  -- '0' -> pad leading space with zeros in a field width.
// note: Flags can appear in any order
// examples:
       printf("|%05d|\n", 123);  // output: |00123|
       printf("|%50d|\n", 123);  // output: width of 50 with 123 at the right
       printf("|%d|\n", -5);     // output: |-5|
       printf("|%d|\n", 5);      // output: |+5|
       printf("|%0#10x|\n", 0xb);// output: |0x0000000b|

// To search manuals in linux
// man printf (runs "less" to show docs (type 'q' to quit))
// insert a number after 'man' to search a specific chapter



// The scanf Function (p.62)
//__________________________
// * Used to read from stdin:
// text stream -> scanf -> binary data
// * Syntax:
// int scanf(<format string>, <addresses...>);
// ^^^ returns the number of successful conversions, ex:
       scanf("%d", &myInt); //('&' is the address operator)

// Syntax for scaf conversion code:
//____________________________________________________________
//| % (required) | Flag | Max Width | Size | Code (required) |
//       #1         #2       #3        #4           #5

// #5: Code
// * Same as printf
// "%c" takes white space, " &c" skips white space
// using a - between variables will take multiple variables in one scan. ex:
       result = scanf("%d-%d-%d", &area, &prefix, &suffix);

// #3: Max Width
// * The max number of characters to read for one conversion, ex:
       scanf("%3d", &myInt); // inside the STD BUFFER '1' '2' '3' '4' '5' '\n', cuts off at 3 because only takes 3 ints

// #4: Size
// * Same as printf, but use "lf" for doubles. ex:
       scanf("%lf", &myDouble);
       scanf("%f", &myFloat);

// #2: Flag
// * Only one flag: '*'
//  This is the "assignment suppression" flag.
//  Allows scanf to discard extracted data.
// ex: Read int... char.. int, and sicard the char.
       scanf("%d%c%d", &int1, &temp, &int2); // This works
       scanf("%d%c%d", &int1, &int2); // This works too, the char will be discarded anyway

// A scanf format string may contain:
// 1) conversion specifiers
// 2) Whitespace
//  - only applies for char data
//  - discards any leading white space
//  ex: Read an int and a char:
       scanf("%d %c", &intVal, &charVal); // output: 123 x (that space gives it an exception to expect a whitespace.)
// 3) Anything else that must appear in the input.
//  ex: Read the date in MM/DD/YY format
       scanf("%d/%d/%d", &month, &day, &year); // this would return an int of 3 for 3 successful scans

// scanf considers extraction complete when:
//  1) it encounters EOF (End of file/input)
//      - To generate EOF from keyboard, type Ctrl + d.
//      - scanf will return EOF as a value.
//  2) An invalid character is read.
//      - invalid char is left on the input stream.
//  3) If the max width is reached. ex:
       result = scanf("%d", &intVal);
//      What are the possibilities?
        if(EOF == result)
       {
           // EOF reached... intVal untouched
       }
       else if(0 == result)
       {
           // failed extraction, intVal untouched
       }
       else
       {
           // Success!!
       }



// Loops
//_______

// 3 types:
// 1) while (p.310)
    while (<bool.expr.>)
       {
           <program statements>;
       }
// 2) do/while (p.319)
    do {
            <program statements>;
       } while (<bool.expr.>);
// 3) for (p.315)
       for(<start>; <bool.expr.>; <action>)
       {
           <program statements>;
       } // (All fields < > are optional, ';' is required however.)
