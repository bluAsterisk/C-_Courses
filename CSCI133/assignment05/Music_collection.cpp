//
//  Music_collection.cpp
//  assignment05
//
//  Created by ケビン・ファン on 2/29/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>
#include <string>
#include "Music_collection.h"

bool Music_collection::add_tune(const Tune &t)
{
    if(number > max)
    {
        return false;
    }
    else
    {
        collection[number++] = t;
        return true;
    }
}

bool Music_collection::set_tune(int index, const Tune &t)
{
    if(index > number)
    {
        return false;
    }
    else
    {
        collection[index] = t;
        return true;
    }
}

Music_collection & Music_collection::operator= (const Music_collection &m)
{
    if(this != &m)
    {
        number = m.number;
        max = m.max;
        delete[] collection;
        collection = new Tune[max];
        for(unsigned int i = 0; i < max; i++)
        {
            collection[i] = m.collection[i];
        }
    }
    return *this;
}
    
ostream& operator<< (ostream &out, const Music_collection &m)
{
    for(unsigned int i = 0; i < m.number; i++)
    {
        out << m.collection[i].get_title();
    }
    return out;
}
    
const string& Tune::get_title() const
{
    return title;
}
    