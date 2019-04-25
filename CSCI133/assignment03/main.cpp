//
//  main.cpp
//  asignment03
//
//  Created by ケビン・ファン on 2/11/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>
#include "IntVector.h"
/*This is the IntVec Test
 */


using namespace std;

int main()
{
    /*
    // test insert
    IntVector vec(5, 7);
    vec.insert(1, 20);
    cout << "The capacity of vec is: " << vec.capacity() << endl;
    cout << "The size of vec is: " << vec.size() << endl;
    cout << "The contents of vec are: " << endl;
    for (unsigned i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << "\n\n";
    
    // test for erase
    vec.erase(5);
    cout << "The capacity of vec is: " << vec.capacity() << endl;
    cout << "The size of vec is: " << vec.size() << endl;
    cout << "The contents of vec are: " << endl;
    for (unsigned i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << "\n\n";
    
    //test push back
    cout << "Testing push back function \n";
    vec.push_back(8);
    cout << "The capacity of vec is: " << vec.capacity() << endl;
    cout << "The size of vec is: " << vec.size() << endl;
    cout << "The contents of vec are: " << endl;
    for (unsigned i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << "\n\n";

    // test insert again
    cout << "Testing insert function \n";
    vec.insert(4, 66);
    cout << "The capacity of vec is: " << vec.capacity() << endl;
    cout << "The size of vec is: " << vec.size() << endl;
    cout << "The contents of vec are: " << endl;
    for (unsigned i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    
    cout << "\n\n";
    
    cout << "The value at the front of vec is " << vec.front() << endl;
    cout << "The value at the back of vec is " << vec.back() << endl;
    cout << "\n\n";
    return 0;*/
    IntVector v;
    cout << "Testing default constructor\n";
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    cout << "Testing empty member function\n";
    if (v.empty())
        cout << "v is empty\n";
    else
        cout << "v is not empty\n";
    cout << "\n\n";
    
    IntVector v2(5);
    cout << "Testing one parameter constructor\n";
    cout << "size: " << v2.size() << "\tcapacity: " << v2.capacity() << endl;
    cout << "Testing empty member function\n";
    if (v2.empty())
        cout << "v2 is empty\n";
    else
        cout << "v2 is not empty\n";
    
    cout << "Testing at function by displaying contents of v2\n";
    for (unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;
    cout << "\n\n";
    
    IntVector v3(5,9);
    cout << "Testing two parameter constructor\n";
    cout << "size: " << v3.size() << "\tcapacity: " << v3.capacity() << endl;
    cout << "Testing empty member function\n";
    if (v3.empty())
        cout << "v3 is empty\n";
    else
        cout << "v3 is not empty\n";
    
    cout << "Testing at function by displaying contents of v3\n";
    for (unsigned i = 0; i < v3.size(); i++){
        cout << v3.at(i) << " ";
    }
    cout << endl;
    cout << "\n\n";
    
    cout << "Testing push_back() function\n";
    for (unsigned i = 0; i < 10; i++){
        v.push_back(i);
        cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    }
    
    cout << endl;
    cout << "Testing pop_back() function\n";
    v.pop_back();
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    v.pop_back();
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl << endl;
    
    
    cout << "Testing front and back functions\n";
    cout << "front: " << v.front() << "\tback: " << v.back() << endl;
    
    cout << "\nTesting insert() function by inserting at position 5\n";
    v.insert(5,100);
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    
    cout << "\nTesting erase() function by erasing position 6\n";
    v.erase(6);
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    
    cout << "\nTesting resize() function (one parameter)\n";
    v.resize(20);
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    v.resize(10);
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    
    cout << "\nTesting resize() function (two parameter)\n";
    v.resize(20, 101);
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    v.resize(10, 101);
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    
    cout << "\nTesting assign() function\n";
    v.assign(5, 102);
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    
    cout << endl;
    cout << "Testing clear() function\n";
    v.clear();
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
     
}
