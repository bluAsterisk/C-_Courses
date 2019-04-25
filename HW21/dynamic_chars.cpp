#include <iostream>
using namespace std;

const int BUFLEN = 26;

void FillStr(char *charArray, char start, int size = BUFLEN);
void DispStr(char *strPtr, int size = BUFLEN);

int main(void)
{
    char *charArray = new char [BUFLEN +1];
    // ask user for upper and lower case
    char response;
    cout << "(U)ppercase or (L)owercase? ";
    cin >> response;
    
    if ('U' == toupper(response))
        FillStr(charArray, 'A');
    else if ('L' == toupper(response))
        FillStr(charArray, 'a');
    else
        cout << "Invalid response..." << endl;
    
    // display the array
    DispStr(charArray);
    
    // release the dynamic memory
    delete [] charArray;
    
    return 0;
}

void FillStr(char *charArray, char start, int size)
{
    for (int index = 0; index < size; ++index) {
        charArray[index] = start + index
    }
    charArray[size] = 0;
}

void DispStr(char *charArray, int size)
{
    for (int index = 0; index < size; ++index) {
        cout << charArray[index];
    }
    cout << endl;
}