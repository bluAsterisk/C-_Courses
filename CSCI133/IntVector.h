//
//  IntVector.h
//  assignment02
//
//  Created by ケビン・ファン on 2/9/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef __assignment02__IntVector__
#define __assignment02__IntVector__

#include <stdio.h>
#include <cstdlib>

class IntVector
{
public:
    // constructors
    IntVector()
    {
        sz = 0;
        cap = 0;
        data = NULL;
    }
    
    IntVector(unsigned size)
    {
        sz = size;
        cap = size;
        data = new int[size];
        for (unsigned i = 0; i < sz; i++) {
            data[i] = 0;
        }
    }
    
    IntVector(unsigned size, int value)
    {
        sz = size;
        cap = size;
        data = new int[size];
        for(unsigned i = 0; i < sz; i++)
        {
            data[i] = value;
        }
        
    }
    // member functions
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int &at(unsigned index) const;
    void insert(unsigned index, int value);
    void erase (unsigned index);
    const int & front() const;
    const int & back()const;
    void assign(unsigned n, int value);
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned size);
    void resize(unsigned size, int value);
    void reserve(unsigned n);
    
    // destructor
    ~IntVector()
    {
        delete[] data;
    }
    
private:
    // helper functions
    void expand();
    void expand(unsigned ammount);
    
    // data variables
    unsigned sz;
    unsigned cap;
    int *data;
};
#endif /* defined(__assignment02__IntVector__) */
