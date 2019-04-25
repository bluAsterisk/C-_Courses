//
//  Week 4.c
//  CSCI 223
//
//  Created by ケビン・ファン on 2/23/16.
//
//

#include <stdio.h>

#define GENERIC_READ
#define GENERIC_WRITE
#define GENERIC_EXECUTE

CreateFile( ~~~, ~~~, ~~~, GENERIC_READ|GENERIC_WRITE|GENERIC_EXECUTE);

// To derive 1's complement, just flip the bits.
// The value of the original with the flip adds up to 15 in hexadecimal.

// The XOR Operator (p.885)
//__________________________
// Means "exclusive or" operator
// * Typically used to toggle bits.
 b1 | b2 | b1^b2
 =============
  0 |  0  |  0
  0 |  1  |  1
  1 |  0  |  1
  1 |  1  |  0
// As shown, the bit is only true if only one bit is true.
// ex:
  1001 1101
^ 0001 0000
===========
  1000 1101
// * Could be used for encrytption, for example:
# define MASK 0x10

inChar = getchar();
putchar(inchar^MASK);
// * Swap values:
// ex:
val1 = 5;
val2 = 12;

val1 ^= val2;
val2 ^= val1;
val1 ^= val2; // the variables have switched bit values




// The Ones Complement (~) (p.886)
//________________________________
// * Unary operator, inverts bits.
// ex:
~0x72 // becomes 0x8D
// * Can be helpful in creating bit masks.
// ex: clear bits 1 and 2
    1001 1001
 &  1111 1001 = F9
// a) 0xF9
// b) ~0x06, this is the inverted bit mask



// The Left Shift Operator (<<) (p.892)
//____________________________________
// * Shifts bits to the left.
// ex:
7 << 0; // takes value 7 and shifts it to the left 0 spaces.
0000 0111 = 7
7 << 1; // takes value 7 and shifts it to the left 1 space.
0000 1110 = 14
7 << 3; // takes value 7 and shifts it to the left 3 spaces.
0011 1000 = 56
// as seen, the value generally doubles the previous value.
// * The MSBs (most significant bit) are lost,
//   while zeros are pushed to the LSBs (least significant bit).



// The Right Shift Operator (>>) (p.890)
//______________________________________
// * Shifts bits to the right.
// * Zeroes are always pushed into the MSB for positive and unsigned values.
// (Just as the << doubles the value, >> halves the value)
// * But with a signed negative, the results are undefined in C:
//  a) If 1's are shifted into MSBs, it's an "arithmetic right shift".
//  b) If 0's are shifted into MSBs, it's a "logical right shift".
// * LSBs are lost since they are pushed off the right end of the byte.

auto char   schar = 0xFF;
auto unsigned char uchar =0xFF;
if(0xFFFFFF00 & schar) // enters because 0xFFFFFF00 & 0xFFFFFFFF = 0xFFFFFF00. since this is signed F is extended to remain negative.
{
    puts("foo");
}
else
{
    puts("bar");
}
if(0xFFFFFF00 & uchar) // enters because 0xFFFFFF00 & 0x000000FF = 0x00000000
{
    puts("foo");
}
else
{
    puts("bar");
}
// automatic conversions occur with bit operators when writing expressions with mixed types



// Switch Statements(p.255)
//_________________________
// Syntax:
switch(<some kind of integer>) // this includes chars too, but not floats/doubles
{
    case <compile-time constant>: // const in C is read only
    {
        <program statements>
        break;
    }
    case <compile-time constant>: // case labels must be unique, or else it won't compile!
    {
        <program statements>
        break;
    }
    default: // optional to have a default case, but its good to have one.
    {
        <program statements>
        break;
    }
}
// comparing const in C and C++
const int max = 500;
// note:
// in C++, this is a compile-time constant
// in C, it's just a read-only variable.
// example for user responses
response = getchar();
switch(toupper(response))
    {
        case 'A':
            Add();
            break; // break isn't required, but generally you wanna use it
        case 'D':
            Delete();
            break;
        default:
            puts("Invalid char...");
            break;
    }



// Jump Statements(p.338)
//_______________________
// * break - terminates a loop, or jumps out of a switch
// * continue - immediately jumps to next loop iteration
// ex:
for(count = 1; count <= MAX_GUESSES; count++)
{
    // get guess...
    if(guess is invalid)
    {
        puts("Oops, lost a turn...");
        continue; // this ends the turn and goes to the next count of the loop
        // break would break out of the loop.
    }
    // maybe more code after this...
}
// * goto - allows you to jump to arbitrary offsets in a function
//  - place labels in function
//  - then, you can "go to" that label
// ex:
int main()
{
    auto int intVal;
L1: // this is a goto label
    // get intVal from user...
    if(intVal < 0)
    {
        goto L1; // takes you to the L1 label again
    }
L2: // another goto label
    // get intVal
    if(intVal < 0)
    {
        goto L1;
    }
    else if(intVal > 0)
    {
        goto L2;
    }
    else
    {
        goto L3;
    }
L3:
    return 0;
}
// goto can make the code difficult to follow since it jumps all over the place



// The Conditional Operator (p.247)
//_________________________________
// * Ternery operator, works like a little if/else statement
// * Syntax:
<expression> ? <true expression> : <false expresion>
// ex:
// A)
if(a > b)
{
    max = a;
}
else
{
    max = b;
}
// B)
max = (a > b) ? a : b;

// ex:
x = 3;
y = 2;
result = (x < y) ? (y > x) ? 10: 20: x == y ? 100 : 200;
result = ((x < y) ? ((y > x) ? 10 : 20): (x == y ? 100 : 200)); // evaluate the parenthesis each