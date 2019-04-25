//
//  IntList.cpp
//  assignment07
//
//  Created by ケビン・ファン on 3/7/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>
#include "IntList.h"
using namespace std;

//Accessors
void IntList::display() const
{
    IntNode *curPtr;
    curPtr = head;
    while(curPtr != NULL)
    {
        cout << curPtr->data << " ";
        curPtr = curPtr->next;
    }
}

//Mutators
void IntList::push_front( int value )
{
    if(head == NULL) //if list is empty
    {
        head = new IntNode(value);
        tail = head;
    }
    else if(head == tail) //if one item in list
    {
        head = new IntNode(value);
        head->next = tail;
    }

    else //if more than one item in list
    {
        IntNode *tempPtr;
        tempPtr = new IntNode(value);
        tempPtr->next = head;
        head = tempPtr;
    }
}

void IntList::push_back( int value )
{
    if(head == NULL) //if list is empty
    {
        head = new IntNode(value);
        head = tail;
    }
    else if(head == tail) //if one item in list
    {
        tail = new IntNode(value);
        tail->next = NULL;
    }
    else //if more than one item in list
    {
        IntNode *tempPtr;
        tempPtr = new IntNode(value);
        tail->next = tempPtr;
        tail = tempPtr;
    }
}

void IntList::pop_front()
{
    //case 1: No nodes
    if(head == NULL)
    {
    }
    //case 1: One node
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    //case 3: More than one node
    else
    {
        IntNode *temp;
        temp = head;
        head = head -> next;
        delete temp;
        temp = NULL;
    }
}

void IntList::select_sort()
{
    for(IntNode *i = head; i != NULL; i = i->next)
    {
        IntNode *least = i;
        for(IntNode *ptrVal = i; ptrVal != NULL; ptrVal = ptrVal->next)
        {
            if(ptrVal->data < least->data)
            {
                least = ptrVal;
            }
        }
        int temp = i->data;
        i->data = least->data;
        least->data = temp;
    }
}

void IntList::insert_sorted(int value)
{
    //insert a new node
    IntNode *tempPtr;
    tempPtr = new IntNode(value);
    tail->next = tempPtr;
    tail = tempPtr;
    
    //sort the linked list
    for(IntNode *i = head; i != NULL; i = i->next)
    {
        IntNode *least = i;
        for(IntNode *ptrVal = i; ptrVal != NULL; ptrVal = ptrVal->next)
        {
            if(ptrVal->data < least->data)
            {
                least = ptrVal;
            }
        }
        int temp = i->data;
        i->data = least->data;
        least->data = temp;
    }
}

void IntList::remove_duplicates()
{
    //sort the linked list
    for(IntNode *i = head; i != NULL; i = i->next)
    {
        IntNode *least = i;
        for(IntNode *ptrVal = i; ptrVal != NULL; ptrVal = ptrVal->next)
        {
            if(ptrVal->data < least->data)
            {
                least = ptrVal;
            }
        }
        int temp = i->data;
        i->data = least->data;
        least->data = temp;
    }
    //deletes the duplicates
    for(IntNode *m = head; m != NULL && m->next != NULL; m = m->next)
    {
        if(m->data == m->next->data)
        {
            IntNode *duplicate, *nexPtr;
            nexPtr = m->next->next;
            duplicate = m->next;
            m = nexPtr;
            delete duplicate;
        }
        else if(m->next->next == NULL)
            break;
    }
}