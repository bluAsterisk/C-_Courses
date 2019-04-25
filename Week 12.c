//
//  Week 12.c
//  CSCI 223
//
//  Created by ケビン・ファン on 4/19/16.
//
//

#include <stdio.h>

// Linked lists (p.928)
// ____________________
typedef struct LNode
{
    int intVal;
    struct LNode *next;
} LNode;
// main
auto LNode node1;
auto LNode node2;
auto LNode node3;

node1.intVal = 10;
node2.intVal = 20;
node3.intVal = 30;

node1.next = &node2;
node2.next = &node3;
node3.next = NULL;

printf("%d\n", node1.next->intVal); // 20
printf("%d\n", node1.next->next->intVal); // 30

auto LNode *ptr;
ptr = &node1;

//traverse the linked list
while(ptr != NULL)
{
    printf("%d\n", ptr->intVal);
    ptr = ptr->next;
}
//10
//20
//30

// Node illustration
node1[0x100]
|   10   |   0x108   |
.intVal   .next

node2[0x108]
|   20   |   0x122   |
.intVal   .next

node3[0x112]
|   30   |   NULL   |
 .intVal  .next

ptr[0x120]
|      |      |
.intVal  .next



// declaring the head node
// main
auto LNode *head = NULL; // list is empty
head = AddNode(head, 30); // takes the address of the node returned
head = AddNode(head, 20);
head = AddNode(head, 10);

// Implementation of AddNode
LNode* AddNode(LNode *headPtr, int intParam)
{
    auto LNode nodePtr;
    nodePtr = malloc(sizeof(LNode)); // points to the address allocated from the heap
    if(NULL == nodePtr)
    {
        //error...
        return headPtr;
    }
    nodePtr->intVal = intParam;
    nodePtr->next = headPtr;
    return nodePtr;
}



// Insertion Strategys
// ___________________
// Front (5)
n5.next = head;
head = n5;

// Middle

// End (55)
n50.next = n55;


|      |      |                               ->|  35  |      |                    ->|  55  |      |
|  10  |      | ->|  20 |      | ->|  30  |      | ->|  40  |      | ->|  50  |      |



// File I/O (p.396)
// ________________
// * "High-level" stream functions;
//      - buffered I/O
//      - support formatting data

// Steps to File I/O
// _________________
// * Declare a variable of type FILE*
// * Call "fopen" function to open a file
// * Pass the pointer to stdlib functions
// * Close file when done.

// ex: Display a file to stdout.
int main(void)
{
    auto int inChar;
    auto FILE *fPtr;
    fPtr = fopen("foo.txt", "r"); // r is to set the mode of the file for read access
    if(NULL == fPtr)
    {
        // unable to open file...
    }
    while(EOF != (inChar = fgetc(fPtr)))
    {
        putchar(inChar); // read each char and print it to STDOUT
    }
    fclose(fPtr); // close the file stream passing the file pointer
}



// Two-Dimensional Arrays(p.509)
// _____________________________
// * An array of 1D arrays.
//main
auto int myInts[3][5] = // [rows][collumns] "row major form"
{
    {5, 4, 2, 9, 6},
    {9, 6, 6, 7, 3},
    {12, 2}
};
myInts[2][2] = 18; // adds 18 to the 3rd row on the 3rd collumn
DispMatrix(myInts, 3); // don't pass the number of collumns

DispMatrix(int matrix[][5], int numRows) // need to pass the collumns in function heading (compile-time constant)
{
    int row;
    int col;
    for(row = 0; row < numRows; ++row) // display for each row
    {
        for(col = 0; col < 5; ++col) // display each element in each row by collumn number
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

// Some interesting expressions:
myInts // pointer to an array (int**). So its basically a pointer to a pointer, in this case pointer to array base address
*myInts // int* (1st row, 1st col) address
**myInts // int (1st row, 1st col) integer value dereferenced
myInts[1] // int* (2nd row, 1st col) address said index in the matrix
*myInts[1] // int (2nd row, 1st col) integer value of index in matrix
myInts[1] + 1 // int* (2nd row, 2nd col) address of said index in matrix

// Apply the "basic rule" to 2D arrays
myInts[i][j]
*(myInts + i)[j]
*(*(myInts + i) + j)

// Compiler generates a storage map equation for 2D arrays:
*(&myInts[0][0] + (i * 5) + j)

// Dynamic 2D Arrays
// _________________
// (A)
int **ptrPtr; //(int**) you can make an array of pointers to ints
// then those pointers in each index can store an integer value

// (B)
int **ptrPtr;
// have the int** point to base address, then have each int* point to an offset.
// this simulates a 2D array when the array of pointers is all in one array (separated by offsets)