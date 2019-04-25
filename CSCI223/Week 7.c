//
//  Week 7.c
//  CSCI 223
//
//  Created by ケビン・ファン on 3/15/16.
//
//

#include <stdio.h>

// Make File Switches
// __________________
// -f => specify makefile name, ex:
make -f dispints.mak
// -B => build all targets
// -n => display commands, but don't execute
// -p => prints environtment variables
// * The "touch" utility will update a file's timestamp: ex:
touch disphex.h
make
// this updates the makefile without having to open it



// Pointers (p.557)
// ________________
// * A pointer variable stores a value, which is an address. It has a data type associated with it. ex:
auto int *intPtr; // <-- type "ptr to int"



// Pointer Operators
// _________________
// 1) "&" - the address operator -> "the address of..."
// 2) "*" - the dereference operator -> "whatever is pointed to by..." ex:
int main (void)
{
    auto int count = 10;
    auto int *intVal;
    auto int *intPtr;
    intPtr = &count; // intPtr points to address of count
    intVal = *intPtr; // intVal is assigned to the value stored to what intPtr is pointing to, which is count
    printf("%d, %d \n", count intVal);
}
// ex:
int main (void)
{
    auto int int2;
    auto int int2;
    auto int *ptr1;
    auto int *ptr2;
    int1 = 23; // int 1 assigned to 23
    prt1 = &int1; // prt1 points to address of int1
    int2 = *ptr1 / 2 + 10; // int2 assigned to value at ptr1 / 2 + 10
    ptr2 = ptr1; // ptr2 points to ptr1
    printf(%d,%d,%d,%d, int1, int2, *ptr1, *prt2); // output: 23, 21, 23, 23
}

void Foo(int *ptr);
int main(void)
{
    auto int intVal = 17;
    auto int *intPtr = &intVal;
    printf("%d \n", intVal); // output: 17
    Foo(intPtr); // or Foo(&intVal); would work too
    printf("%d \n", intVal); // output: 42
}

void Foo(int *ptr)
{
    *ptr = 42;
}

// STDOUT
// Enter a double: 32.4
// myDouble = 32.4

int main (void)
{
    auto double myDouble;
    GetData(&myDouble);
    printf("myDouble = %f \n", myDouble);
}

void GetData (double *ptr)
{
    printf("Enter a double: ");
    scanf("%lf", ptr);
    // assign the value to the pointer, which is actually the address of the double passed.
}



int main (void)
{
    auto int int1 = 37;
    auto int int2 = 12;
    Swap(&int1, &int2);
}

void Swap(int *ptr1, int *ptr2)
{
    auto int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


// Pointers and Arrays
// ___________________
// ex:
auto int *intPtr;
auto int myInts[5] = {11, 22 ,33 ,44 ,55};
intPtr = &myInts[0]; // a
intPtr = myInts;     // b
// Observations
&myInts[0] == 0x84 == intPtr + 0;
&myInts[1] == 0x88 == intPtr + 1;
&myInts[2] == 0x8C == intPtr + 2;
// notice that each address is upped by 4 in hex due to the size of an int, which is 4 bytes.
// More observations
myInts[0] == 11 == *(intPtr + 0);
myInts[1] == 22 == *(intPtr + 1);
myInts[n] == .. == *(intPtr + n);
// Basic Rule: a[i] == *(a+i)
auto int result;
ptr = myInts;
ptr += 2;
result = ptr - myInts; // this gives 2 because its 2 int offsets from the address ptr is currently at

int main(void)
{
    auto char array[] = "0123456789";
    auto int index = 5;
    printf("%c \n", array[index]); // 5 -> *(array + index)
    printf("%c \n", array[index]); // 5 -> *(index + array)
}


// Pointer Arithmentic
// ___________________
// * You can add/subtract an integer offset to/from a pointer to derive an address.
// * You can subtract one pointer from another. (must be pointers to the same type)
// * You cannot add two pointers.


// Void Pointers (p.580)
// _____________________
// ex:
int main (void)
{
    auto int intVal =5;
    auto int *intPtr = &intVal;
    auto void *voidPtr;
    voidPtr = intPtr;
    *voidPtr = 12; // this won't compile because its a pointer to a void.
    // all void pointers do is store an address, that's why you can't make changes.
    *(int*)voidPtr = 12;
}
// * Aka, "generic ptrs", they have no data type associated with them.
// * Thus, they cannot be dereferenced, and you cannot do pointer arithmetic.
// note: However, this means it doesn't matter what type variable you are pointing to.


auto int myInts[5] = {11, 22 ,33, 44, 55};
auto int yourInts[5];
// copy myInts to yourInts
memcpy(yourInts, myInts, sizeof(myInts)); // memcpy(<destination>, <source>, <number of bytes>)
// another possible implementation:
void memcpy(void *dPtr, void *sPtr, numBytes)
{
    auto char *destPtr = dPtr;
    auto char *srcPtr = sPtr;
    while (numBytes > 0)
    {
        *destPtr = *srcPtr;
        ++destPtr;
        ++srcPtr;
        --numBytes;
    }
}