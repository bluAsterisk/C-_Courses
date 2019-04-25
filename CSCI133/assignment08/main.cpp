#include <iostream>
#include <cstring>
#include "CharStack.h"
#include "ParenMatch.h"

using namespace std;

void outputResult(char [], int);

int main(){
    char s1[] = "(2x + 5) (3x+4)";
    char s2[] = "[(8x+2) -3x[4x+1]]";
    char s3[] = "{(8x+2) -3x[4x+1]]";
    char s4[] = "(((8x+2) -3x[4x+1])))";
    char s5[] = "{(8x+2) -3x[4x+1]}";
    outputResult(s1, strlen(s1));
    outputResult(s2, strlen(s2));
    outputResult(s3, strlen(s3));
    outputResult(s4, strlen(s4));
    outputResult(s5, strlen(s5));
}

void outputResult(char a[], int sz){
    if (ParenMatch(a, sz)){
        cout << a << " has matching parentheses" << endl;
    }
    else
        cout << a << " does not have matching parentheses" << endl;
}

