//
//  QueueEmpty.h
//  assignment09
//
//  Created by ケビン・ファン on 3/18/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef assignment09_QueueEmpty_h
#define assignment09_QueueEmpty_h

// User-defined exception class.

class QueueEmpty
{
public:
    //place any public member variables/functions here
    QueueEmpty() // default constructor
    {
        error = "Empty Queue";
    }
    QueueEmpty(string strVal) // constructor with given string
    {
        error = strVal;
    }
    string what();
private:
    //place any private member variables/functions here
    string error;
};

string QueueEmpty::what()
{
    return error;
}
#endif
