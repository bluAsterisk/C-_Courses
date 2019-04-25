#include <iostream>
using namespace std;

void DisArray(int * intPointer, int numElem);

in main(void)
{
    int numInts;
    int *intArray;
    
    // ask user for number of integers
    cout << "Ether the number of integers: ";
    cin >> numInts;
    
    // dynamically allocate an array
    intArray = new int[numInts];
    
    // initialization
    for (int index = 0; index< numInts; ++index) {
        intArray[index] = index +1;
    }
    
    // call function to display array
    DisArray(intArray, numInts);
    
    //release dynamic memor back to heap
    delet [] intArray;
    
    retun 0;
}

void DisplayArray(int *intArray, int numElem)
{
    for (int index = 0; index < numElem; ++index) {
        cout << intArray[index] < endl;
    }
}