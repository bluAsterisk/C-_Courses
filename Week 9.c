//
//  Week 9.c
//  CSCI 223
//
//  Created by ケビン・ファン on 3/29/16.
//
//

#include <stdio.h>

int main(void)
{
    auto int myInts[5] = {11, 22, 33, 44, 55};
    DispInts(myInts, 5);
}

DispInts(int array [], int numElems)
// or the array can be passed like *array, since the base address is a pointer
{
    auto int *ptr = array;
    auto int *endPtr = array + numElems; //this goes beyond the array boundaries, however...
    for( ;ptr < endPtr; ++ptr)
    {
        printf("%d\n", *ptr);
    }
    // this loop will terminate because the endPtr will no longer be larger than ptr, but equal to it.
}

// The NULL Pointer
// * Has an integer value of zero.
// * Dereferencing a NULL ptr is undefined, but almosys always crashes a program.
// * NULL is used to tell if a ptr is pointing to anything (or not)

// a segmentation fault typically means you are trying to access data that does not belong to you.
int *g_ptr;

int main(void)
{
    printf("%d\n", *g_ptr); // since g_ptr was not initialized and it is being dereferenced, it is automatically set to NULL. Which is zero. This would give you a segmentation fault.
    auto int *intPtr = NULL; // this points the pointer to nothing.
}

void Foo(int *ptr)
{
    if(ptr) // if this pointer is pointing to something (not NULL), this would evaluate to true
    {
        // safe to use ptr
    }
}



// Dynamic Memory Management (p.629)
// _________________________________
// * Allocating and releasing heap memory at runtime.
// * Stdlib functions:
//      - void* malloc(size_t size); (memory allocation)
//                              ^--- number of bytes
//          - returns base address of allocated block, or NULL upon failure
//          - content of block is undefined
//      - void* calloc(size_t numElems, size_t elemSize);
//                              ^-- elements      ^-- bytes for 1 element
//          - returns NULL on failure
//          - block is set to bitwise zero
//      -void* realoc(void *ptr, size_t size);
//                          ^           ^-- number of byes for new block
//                          | ptr returned from previous call to malloc or calloc
//          - used to increase/decrease size of heap allocaions.
//      - void free(void *ptr);
//                          ^-- ptr to heap block
// * Safe to use these in C++, but malloc/calloc know nothing about constructors,
//   free doesn't know anything about destructors either.
// ex: Dynamic array of grades:
int main(void)
{
    auto double *grades;
    auto int numGrades;
    auto int index;
    // get numGrades from user...
    grades = malloc(numGrades * sizeof(double));
    for(index = 0; index < numGrades; ++index)
    {
        printf("Enter grade number %d: ", index + 1);
        scanf("%lf", grades + index);
    }
    // loop and display grades...
    for(index = 0; index < numGrades; ++index)
    {
        printf("Grade #%d: %f\n", index + 1, grades[index]);
    }
    free(grades);
}



// Strings(p.665)
// ______________
// * A string is a null-terminated character array.
// ex:
auto char str1[] = {'a', 'b', 'c', 0}; // this works, or you can do this...
auto char str1[] = "abc";
auto char *strPtr = "abc"; // this works too because it is pointing to the base address
printf("%p\n"), "abc"); // this would give the address where that string is pointing to
printf("%s\n", strPtr); // this also gives the address of the pointer



// Reading Strings from stdin
// __________________________
// * scanf("%s", buf);
// ex:
auto char buf [LEN];
printf("Enter a string: ");
scanf("%s", buf); // "C is fun!"
printf("buf = %s\n", buf); // only outputs C since it sees whitespace as a delimiter
//  - uses whitespace as a delimiter
// * gets - reads a string form stdin(including whitespace). ex:
gets(buf);
//  - deprecated, shouldn't use it because its very prone to hacking
// * fgets - like gets, but takes max bytes argument. ex:
fgets(buf, LEN, stdin);
//  - copies the trailing '\n' character
//  - reading stops when '\n' or EOF is encountered
//  - returns ptr to buffer on success, or NULL on failure, or EOF



// Dynamic Copy of a String
// ________________________
auto char buf[LEN];
auto char *ptr;
fgets(buf, LEN, stdin);
ptr = malloc(strlen(buf) + 1) // +1 for the null in the string
strcpy(ptr, buf);
free(ptr);



// const + Pointers
// ________________
char *ptr1;
const char *ptr2;
char *const ptr3;        // <-- Should be
const char * const ptr4; // <-- initialized

// What's Pointed to is const | Data Type | | pointer is const | Identifier
//---------------------------------------------------------------------------
//                            |    char   |*|                  |    ptr1
//--------------------------------------------------------------------------
//           const            |    char   |*|                  |    ptr2
//--------------------------------------------------------------------------
//                            |    char   |*|       const      |    ptr3
//--------------------------------------------------------------------------
//           const            |    char   |*|       const      |    ptr4

*ptr1 = 'Q'; // legal
ptr2 = ptr1; // legal
ptr1 = ptr2; // legal in C, but not in C++...
ptr3 = ptr1; // illegal



// Stdlib String Functions
// _______________________
// * strspn: returns the length of prefix in str1 consisting of chars in str2. ex:
int result;
result = strspn("cabbage", "abc"); // result = 5, that's how many chars match before the g
// * strcspn: returns length of prefix in str1 consisting of chars NOT in str ex:
result = strcspn("tomato", "abc"); // result = 3, that's how many don't match until a
// * strpbrk: Just like strcspn, except it returns a ptr to first char in str that's also in str2 ex:
charPtr = strpbrk("tomato", "abc"); // returns a pointer to a in tomato, if none is found ptr to NULL
// * strchr: returns ptr to first char in str1 that's equal to the char argument. (or NULL) ex:
charPtr = strchr("tomato", 'm');
// * strstr: returns ptr to substring in str1.(or NULL) ex:
charPtr = strstr("greenhouse", "house");



auto char oldName[LEN];
auto char newName[LEN];
auto char *blackPtr;
while(NULL != fgets(oldName, LEN, stdin))
{
    oldName[strlen(oldName) - 1] = 0;
    if((0 == strlen(oldName)) ||
       (NULL == (blankPtr = strchr(oldName, ' '))) ||
       (0 == strlen(blankPtr + 1)))
    {
        puts("Input string is invalid... ");
    }
    else
    {
        strcpy(newName, blankPtr + 1);
        strcat(newName, ",");
        *blackPtr = NULL;
        strcat(newName, oldName);
        printf("%s \n", newName);
    }
}