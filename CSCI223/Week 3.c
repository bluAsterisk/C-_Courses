//
//  Week 3.c
//  CSCI 223
//
//  Created by ケビン・ファン on 2/16/16.
//
//

#include <stdio.h>

// Automatic Type Conversions (p.118)
//_____________________________________
// 1) Arithmetic Type Conversion:
//      - happens in expressions with mixed types
//      - the "smaller" types are converted to the "largest" type. ex:
// myChar + myInt;
//          ____________________
// myInt ->|  x |  x |  x |  x  |
//          ____________________
// myChar->|  o |  o |  o |  x  |
// + _____________________________________
//         |  x |  x |  x |  x  |
// converts to type int
// 2) Assignment Type Conversion
//      - happens when rvalue + lvalue are different types
//      - the rvalue is converted to the lvalue type. ex:
myInt = myChar;
//          ____________________
// myChar->|  o |  o |  o |  x  |
//            |    |    |    |
//            v    v    v    v
//          ____________________
// myInt ->|  o |  o |  o |  x  |
// char gets converted to int
// note: if int gets converted to a char then the excess bytes will be cut off.
// *) Type Cast
//      - allows a temporary and explicit type conversion. ex:
myInt = (int) myDouble; // this tells the compiler what you want to do
// in C++:
myInt = int(myDouble);
myInt = static.cast<int>(myDouble);



// Operators
//_____________________________________
// * Arithmetic: "*", "/", "%" (only works on ints), "+", "-"
// * Relational: ">", "<", ">=", "<=", "==", "!="
//      - automatic type conversions performed
//      - evaluates to 1 (true) or 0 (false)
//      - no order of evaluation imposed on operands. ex:
if (x++ >= y++)
{
    //~ ~ ~ ~ ~
}
// * Logical: "&&" and "||" are binary, "!" is unary
//      - evaluates to 1 or 0
//      - order of evaluation IS imposed. ex:
if ((b1) && (b2) && (b3) && (b4))
{
    // ~ ~ ~ ~
}
// If the first arg is false then the rest of the expression will fail,
// potentially improving run-time. This is called "short-circuit evaluation".
// * Increment/Decrement: "++", '--"
//      - Prefix: (++x)
//          - first variable is modified, then it is used in the expression
//      - Postfix:(x++)
//          - first the variable is used, then it is modified
// ex:
x = 3;
y = ++x; // x = 4, y = 4
y = ++x; // x = 5, y = 5
y = x--; // x = 4, y = 5



// The Comma Operator (p.323)
//______________________________________
// * Allows multiple expressions to evaluate as a single expression.
//     (Evaluates from LEFT to RIGHT) ex:
printf("%d", 1, 2, 3, 4, 5); // output: 1
// arguments are separated by commas
printf("%d", (1, 2, 3, 4, 5)); // output: 5
// comma operator was used inside parenthesis
for(sum = 0, count = 100; sum < count; ++sum, --count) // this works too



// The sizeof Operator (p.171)
//______________________________________
// * Produces the number of bytes required to store a value
// * Syntax: sizeof(<expression>) <---- compile-time operator
// ex:
auto int    myint;
printf("%d", sizeof(myInt));
// can also write sizeof(int), that gives a value of 4 for 4 bytes.



// Digits in Different Bases
//______________________________________
// Decimal: 0 1 2 3 4 5 6 7 8 9
// Binary: 0 1
// Octal: 0 1 2 3 4 5 6 7
// Hexadecimal: 0 1 2 3 4 5 6 7 8 9 A  B  C  D  E  F
//                                  10 11 12 13 14 15



// Counting in Different Bases
//______________________________________
// Decimal      Binary      Octal       Hex
//    0             0          0          0
//    1             1          2          1
//    2            10          .          2
//    3            11          .          .
//    .           100          .          .
//    8           101          6          .
//    9           111          7          8
//   10          1000         10          9
//   11                        .          A
//   12                        .          B
//    .                        .
//    .                       16
//    .                       17
//   18                       20
//   19                       21
//   20                       22
//   21                        .
//    .                        .
//    .                        .
//    .                       76
//   98                      100
//   99
//  100



// Converting to Decimal
//_____________________________________
// 123 -> (1 x 10^2) + (3 x 10^1) + (2 x 10^8)
//      =     100    +     30     +     2
//      = 132
// 0132 -> (1 x 8^2) + (3 x 8^1) + (2 x 8^0)
//      =      64    +     24    +     2
//      = 90 decimal
// 0x132 -> (1x 16^2) + (3x16^1) + (2x16^0)
//       =     256    +    48    +    2
//       = 306 decimal
// 0xCD -> (12 x16^1) + (13 x 16^0)
//       =     192    +     13
//       = 205 decimal




// Binary to Octal
//_______________________________________
// 100 111 100 010
//  4   7   4   2  -> 04742
// 100 000 110 011 101
//  4   0   6   3   5 -> 040635



// Octal to Binary
//_______________________________________
//  0   2   6   5   1
// 000 010 110 101 001



// Binary to Hex
//_______________________________________
// 1100 0010 1010 0011
//   C    4    A    3 -> 0xC2A3
// 0010 1111 1110 0111 1010
//   2    F    E    7    A -> 0x2FE7A



// Hex to Binary
//______________________________________
// 0 x   F    D    4    E    9    6    C
//     1111 1101 0100 1110 1001 0110 1100

// Precedence & Associativity (p.106)
//______________________________________
// * Precedence  is applied before associativity.
// * Binary operators associate left to right (except for '=').
// * Unary operators associate right to left. (Harbison & Steele - "C: A Reference Manual")
//      - Harbison & Steele say "postfix has higher precedence than prefix". ex:
*x++; // *(x++); would be taken.
// example
a = 10;
b = 3;
c = 7;
printf("%d", a + b >= 3 * c == a != 2 * c + b);
//            L4   L5  L3   L6   L6  L3  L4

// Lowest level has priority decending to highest priority
// Level  |  Operator
//____________________
//   1          ()
//   2      unary +, -
//   3          *, /
//   4          +, -
//   5      <, <=, >, >=
//   6          ==, !=



// ________________________
//|  |  |  |  |  |  |  |  |
//  ^___ MSB (Most significant bit, used to count the sign of the int
// if it is switched on (1) then its negative, off (0) then its positive

// 2's Complement (p.1044)
//_______________________________________
// * Used to represent negative numbers
// * To illustrate binary subtraction:
 0  0  1  1
+0 +1 +0 +1
____________
 0  1  1 10
// let's try subtraction
 100110
- 10001
_______
 110101
// When you can't subtract, you borrow a power from the next number.

// To derive 2's complement
//______________________________________
//  -- Flip all bits
//  -- Add 1
// Ex:
+5 -> 0000 0101
// flip and add 1
      1111 1010
     +        1
________________
      1111 1011 <- -5

// 5 - 7 -> 5 + (-7)
+7 -> 0000 0111
//flip
  1111 1000
+ 0000 0001
  1111 1001 <- -7

  0000 0101
+ 1111 1001
  1111 1110 <- -2

// Another way to Derive 2's Comlement
//_______________________________________
//  -- copy bits from right to left until you reach a 1;
//     copy the 1
//  -- invert all remaining bits
// Ex:
0001 0100 <- +20
1110 1100 // take the first value, then flip the rest of the bits



// Ranges of Integer Values
//_______________________________________
//   unsigned             signed
         0      0000         0
         1      0001         1
         2      0010         2
         3      0011         3
         4      0100         4
         5      0101         5
         6      0110         6
         7      0111         7
         8      1000        -8
         9      1001        -7
        10      1010        -6
        11      1011        -5
        12      1100        -4
        13      1101        -3
        14      1110        -2
        15      1111        -1
// smallest: zero       smallest: -(2^(n-1))
// largest : 2^n - 1    largest: +(2^(n-2) - 1)



// Bitwise Operators (p.881)
//_______________________________________
// * "AND" (&)
//  - Typically use to clear target bits
ex:_______________________________
  | 0 | 0 | 1 | 1 | 1 | 1 | 0 | 1 | clear bits #5 and #2
 &  1   1   0   1   1   0   1   1  <-- "bit mask"
====================================
    0   0   0   1   1   0   0   1
// code example:
myChar = 0x3D;
myChar = myChar & 0xDB;
// or
myChar &= 0xDB;

   0x3F -> 0011 1111
&  0x68 -> 0110 1000
=======   ==========
   0x28       2    8
// * "OR" (|)
//  - used to set bits
ex:_______________________________
  | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 1 | set bits #3 and #1
  | 0   0   0   0   1   0   1   0  <-- "bit mask"
====================================
    0   0   1   0   1   0   1   1
// code form:
myChar |= 0x0A;