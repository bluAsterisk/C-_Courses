//
//  CharStack.cpp
//  assignment08
//
//  Created by ケビン・ファン on 3/15/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>
#include<stdlib.h>
#include "CharStack.h"


// constructor
CharStack::CharStack()
{
    head = NULL;
    tail = NULL;
}

// destructor
CharStack::~CharStack()
{
    CharNode *temp;
    while (head != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    head = NULL;
    tail = NULL;
}

// accessors
char CharStack::top() const
{
    return head->data;
}

// mutators
void CharStack::push(char value)
{
    if(head == NULL)
    {
        head = new CharNode(value);
        tail = head;
    }
    else if(head == tail)
    {
        CharNode *tempPtr;
        tempPtr = new CharNode(value);
        head = tempPtr;
        head->next = tail;
    }
    else
    {
        CharNode *tempPtr;
        tempPtr = new CharNode(value);
        tempPtr->next = head;
        head = tempPtr;
    }
}

void CharStack::pop()
{
    if(isEmpty())
    {
        exit(1);
    }
    else
    {
        CharNode *tempPtr;
        tempPtr = head;
        head = head->next;
        delete tempPtr;
        tempPtr = NULL;
    }
}

bool CharStack::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
        return false;
}