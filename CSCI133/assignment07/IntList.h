//
//  IntList.h
//  assignment07
//
//  Created by ケビン・ファン on 3/7/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>

struct IntNode
{
    int data;
    IntNode *next;
    IntNode( int data ) : data(data), next(0) {}
};

class IntList
{
private:
    IntNode *head;
    IntNode *tail;
    
public:
    IntList()
    {
        head = NULL;
        tail = NULL;
    }
    ~IntList()
    {
        IntNode *temp;
        while(head != NULL)
        {
            temp = head->next;
            delete[]head;
            head = temp;
        }
        head = NULL;
        tail = NULL;
    }
    void display() const;
    void push_front( int value );
    void push_back( int value);
    void pop_front();
    void select_sort();
    void insert_sorted( int value );
    void remove_duplicates();
};