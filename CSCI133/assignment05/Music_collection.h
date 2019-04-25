//
//  Music_collection.h
//  assignment05
//
//  Created by ケビン・ファン on 2/29/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef __assignment05__Music_collection__
#define __assignment05__Music_collection__

#include <stdio.h>

#endif /* defined(__assignment05__Music_collection__) */

#include <iostream>
using namespace std;

//The Tune class is ultra­simple:
class Tune
{
private:
    string title;
public:
    Tune()
    {

    }
    Tune( const string &n )
    {
        title = n;
    }
    const string & get_title() const;
};

class Music_collection
{
private:
    int number;// the number of tunes actually in the collection
    int max; // the number of tunes the collection will ever be able to hold
    Tune *collection; // a dynamic array of Tunes: "Music_collection has­many Tunes"
public:
    Music_collection()
    {
        number = 0;
        max = 100;
        collection = new Tune[max];
    }
    // sets max to n
    Music_collection( int n )
    {
        number = 0;
        max = n;
        collection = new Tune[n];
    }
    // default value of max is a conservative 100
    // overloaded copy constructor
    Music_collection( const Music_collection &m)
    {
        number = m.number;
        max = m.max;
        collection = new Tune[max];
        for(unsigned int i = 0; i < max; i++)
        {
            collection[i] = m.collection[i];
        }
    }
    // returns true if add was successful,
    // returns false if not enough room to add
    bool add_tune( const Tune &t );
    // sets the Tune at position index in collection to t,
    // returns true if index < number
    bool set_tune( int index, const Tune &t );
    // overloaded assignment operator
    Music_collection & operator=( const Music_collection &m );
    // Destructor
    ~Music_collection()
    {
        delete[] collection;
    }
    // overloaded stream insertion operator
    // outputs the title of each Tune in the collection on a separate line
    friend ostream & operator<<( ostream &out, const Music_collection &m );
};
