//
//  Week 13.c
//  CSCI 223
//
//  Created by ケビン・ファン on 4/26/16.
//
//

#include <stdio.h>

// Variable-Length Arrays (VLAs) (p.463)
// _____________________________________
// * An array with a runtime dimension. ex:
scanf("%d", &numElems); // could also be a parameter
auto int array[numElems]; // this will create the array AFTER you enter the dimension.
// * Can also do this with 2D arrays.
//  A)
void Foo(int numRows, int numCols)
{
    auto int matrix[numRows][numCols];
}
// B)
// these parameters must appear before the 2D array
void Foo(int numRows, int numCols, int matrix[numRows][numCols])
{
    
}
// * A 2D array allocated from the heap using a ptr to an array:
// ex (with constants)
auto int (*ptr)[5]; // ptr is a pointer to an array of 5 ints
ptr = malloc(3 * sizeof(*ptr));
// ex (with runtime values)
// get numRows/numCols from user...
auto int (*ptr)[numCols];
ptr = malloc(sizeof(int[numRows][numCols]));



// File I/O (continued)
fptr = fopen("foo.txt", "r"); // assign this pointer to the address of the file
if(NULL == fptr)
   {
       // failed to open...
   }
// The Mode Argument to 'fopen' (p.400)
// ____________________________________
// * Is a null-terminated string.
// * Possible modes:
//      - "r" - read-only; if file does not exist, NULL is returned
//      - "w" - write-only; opens an empty file
//      - "a" - append mode, all writes occur at EOF; if file doesn't exist, then its created
//      - "r+" - read/write access; file must exist
//      - "w+" - just like "w", but also allows read access
//      - "a+" - just like "a", but allows read access



// Quick Tour of File Functions
// ____________________________
// * feof - lets you know if EOF has been read
// * fgetc/fputc - just like getchar/putchar, but with file streams
// * fflush - bufer to an output stream
// * fprintf/fscanf - work just like printf and scanf, but it takes a pointer to the file
// * fgets/fputs - read/write lines of text
// note: stdin, stdout, stderr are all type FILE*



// Enumerated Lists (p.748)
// ________________________
// * Used to create compile-time integer constants
// Syntax:
enum <optional tag name> {<id1>, <id2>, <id3>};
// ex:
enum Color {BLUE, RED, GREEN, YELLOW, WHITE}; // B = 0, R = 1, G = 2, Y = 3, W = 4
auto enum Color myColor = RED;
enum {WEST = 4, EAST, NORTH = 3, SOUTH}; // W = 4, E = 5, N = 3, S = 4
// the variables after will be incremented by 1



// Unions (p.782)
// ______________
// * Similar to a struct, but can only store one value at a time.
// * All members have same base address.
// ex:
union Data
{
    char chVal;
    int intVal;
    double dVal;
    // each of these would share the same address, so they only keep a single value.
};

auto union Data myData;
myData.chVal = 'A'; // gets a value of 'A'
myData.intVal = 99; // overwritten with value of 99

// ex:
enum Type {CHAR, INT, DOUBLE};
struct Data
{
    enum Type type;
    union
    {
        char chVal;
        int intVal;
        double dVal;
    }x; // x is a variable of type type
};

auto struct Data myData;
myData.type = INT;
myData.x.intVal = 27;
myData.type = DOUBLE;
myData.dVal = 3.14;
DispData(&myData);

void DispData(struct Data, *data)
{
    switch(data->type)
    {
        case CHAR:
            printf("%c", data->x.chVal);
            break;
            
        case INT:
            printf("%d", data->x.intVal);
            break;
            
        case DOUBLE:
            printf("%f", data->x.dVal);
            break;
    }
}


// Pointers to Functions (p.1097)
// ______________________________
// * Can make pointers to functions members of structs.
// * Can use pointers to functions as arguments to other functions
// ex:
int Add(int v1, int v2)
{
    return v1 + v2;
}
int Sub(int v1, int v2)
{
    return v1 - v2;
}

int main(void)
{
    auto int int1;
    auto int int2;
    auto int result;
    auto int (*fptr)(int, int); // pointer to a function with 2 int args
    //get int1 and int2
    fptr = Add; // if you don't have parethesis, that will be an address of that function
    result = fptr(int1, int2); // calls Add function and assigns it to result
    fptr = Sub; // now we point the pointer to the address of Sub
    result = fptr(int1, int2); // calls Sub function and assigns it to result
}

// ex:
struct MenuItem
{
    char *item;
    int (*fptr)(void);
};

auto struct MenuItem menu[LEN] =
{
    {"add", Add},
    {"sub", Sub},
    {"div", Div},
    {"mult", Mult}
};
for(index = 0; index < LEN; ++index)
{
    printf("%s\n", menu[index].item); // print each array index and the string contained in each "item" ptr
}
// get user choice in a string ("buf")
for(index = 0; index < LEN; ++index)
{
    if(0 == strcmp(buf, menu[index].item))
    {
        result = menu[index].fptr(); // call the function by using the pointer to that function
        break;
    }
}

// Quicksort function
void qsort(void *base, size_t numElems, size_t width, int(*compare)(void *elem1, void elem2));
// width is the number of bytes per element

typedef struct{
    int month;
    int day;
    int year;
}Date;

// main
auto Date dates[LEN] =
{
    {12, 3, 1993},
    {7, 18, 2004},
    {2, 9, 1942}
};
qsort(dates, LEN, sizeof(Date), CompDates);


int CompDates(void *elem1, void elem2)
{
    auto Date *date1 = elem1;
    auto Date *date2 = elem2;
    auto int int1;
    auto int int2;
    int1 = date1->year *10000 + date1->month * 100 + date1->day; // this gives 19730000 + 1200 + 03 = 19731203
    int2 = date2->year *10000 + date2->month * 100 + date2->day; // this gives 20040000 + 700 + 18 = 20040718
    if(int1 < int2)
    {
        return -1;
    }
    else if (int1 > int2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // or you can just return the difference between int1 and int2
}