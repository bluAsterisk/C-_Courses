//
//  ParenMatch.h
//  assignment08
//
//  Created by ケビン・ファン on 3/14/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//
#include "CharStack.h"
bool ParenMatch(char [], int );

// Algorithm ParenMatch(X , n):
// Input: An array X of n tokens, each of which is either a grouping symbol, a
// variable, an arithmetic operator, or a number
// Output: true if and only if all the grouping symbols in X match
bool ParenMatch(char X[], int sz)
{
    /*
    int match1, match2, match3;
    match1 = 0; // variable to check ( )
    match2 = 0; // variable to check { }
    match3 = 0; // variable to check [ ]
    for(unsigned int i = 0; i < sz; i++)
    {
        if(X[i] == '(') // count open parenthesis
            match1++;
        else if(X[i] == '{') // count open curly brace
            match2++;
        else if(X[i] == '[') // count open square bracket
            match3++;
        else if(X[i] == ')') // count closing parenthesis
            match1++;
        else if(X[i] == '}') // count closing curly brace
            match2++;
        else if(X[i] == ']') // count closing square bracket
            match3++;
    }
    if(((match1 % 2) == 0) && ((match2 % 2) ==0) && ((match3 % 2) == 0))
    {
        return true;
    }
    else
        return false;
     */
    CharStack S; // create an empty stack
    for(int i = 0; i < sz; i++) // add the parenthesis/curly brace/square bracket to stack
    {
        if(X[i] == '(' || X[i] == '{' || X[i] == '[') // count open parenthesis
            S.push(X[i]);
        else if(X[i] == ')' || X[i] == '}' || X[i] == ']') // count open curly brace
        {
            if(S.isEmpty())
                return false; // nothing left to match with
            if((S.top() == '(') || (S.top() == '{') || (S.top() == '['))
            {
                if(S.top() == '(' && X[i] == ')') // if parenthesis match
                    S.pop();
                else if(S.top() == '{' && X[i] == '}') // if curly braces match
                    S.pop();
                else if(S.top() == '[' && X[i] == ']') // if square brackets match
                    S.pop();
                else
                    return false;
            }
        }
    }
    if(S.isEmpty())
        return true;
    else
        return false;
}