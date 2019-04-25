//
//  CharStack.h
//  assignment08
//
//  Created by ケビン・ファン on 3/14/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//
#ifndef CHARNODE_H
#define CHARNODE_H
struct CharNode
{
    char data;
    CharNode *next;
    CharNode( char data ) : data(data), next(0) {}
};

class CharStack
{
private:
    CharNode *head;
    CharNode *tail;
public:
    CharStack();
    ~CharStack();
    char top() const;
    void push(char value);
    void pop();
    bool isEmpty();
};

#endif