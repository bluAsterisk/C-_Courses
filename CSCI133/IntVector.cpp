//
//  IntVector.cpp
//  assignment02
//
//  Created by ケビン・ファン on 2/9/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include "IntVector.h"
#include <stdlib.h>

// accessors functions
unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    if (sz == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// private helper functions
void IntVector::expand()
{
    if (cap == 0)
    {
        cap = 2;
    }
    else if(sz >= cap)
    {
        expand(cap);
    }
}

void IntVector::expand(unsigned amount)
{
    cap = cap + amount;
    int *temp = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    temp = NULL;
}

// mutators
void IntVector::insert(unsigned index, int value)
{
    if (index > sz)
    {
        exit(1);
    }
    sz++;
    if (sz >= cap)
    {
        expand();
    }
    data[index - 1] = value;
    for (unsigned int i = index; i < sz; i++)
    {
        data[i + 1] = data[i];
    }
}

void IntVector::erase(unsigned index)
{
    if (index > sz) {
        exit(1);
    }
    for (unsigned i = index; i < (sz - index); i--) {
        data[i] = data[i + 1];
    }
    sz--;
}

void IntVector::push_back(int value)
{
    if (sz >= cap) {
        expand();
    }
    sz++;
    data[sz - 1] = value;
}

void IntVector::pop_back()
{
    --sz;
    if (sz == 0) {
        exit(1);
    }
}

void IntVector::clear()
{
    sz = 0;
}

void IntVector::resize(unsigned size)
{
    if (size < sz) {
        sz = size;
    }
    else if (size > sz)
    {
        if (size > cap) {
            expand();
        }
        sz = size;
        for (unsigned i = size - sz; i < size; i++) {
            data[i] = 0;
        }
    }
}

void IntVector::resize(unsigned size, int value)
{
    if (size < sz) {
        sz = size;
    }
    else if (size > sz)
    {
        if (size > cap) {
            expand();
        }
        sz = size;
        for (unsigned i = size - sz; i < size; i++) {
            data[i] = value;
        }
    }
}

void IntVector::reserve(unsigned n)
{
    if (sz <= n) {
        expand();
    }
    sz = n;
}

void IntVector::assign(unsigned n, int value)
{
    if (n > sz) {
        expand();
    }
    sz = n;
    for (unsigned i = 0; i < sz; i++) {
        data[i] = value;
    }
}

const int & IntVector::at(unsigned index) const
{
    if(index >= sz)
    {
        exit (EXIT_FAILURE);
    }
    return data[index];
}

const int & IntVector::front() const
{
    return data[0];
}

const int & IntVector::back() const
{
    return data[sz - 1];
}
