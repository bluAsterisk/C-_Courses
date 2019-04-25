//
//  main.cpp
//  assignment10
//
//  Created by ケビン・ファン on 4/8/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>
#include "Date.h"
#include "Student.h"
#include "CS133Student.h"

using namespace std;

void PrintAll(Student s[], int sBuff, CS133Student cs[], int csBuff);

int main()
{
    /*
    cout << "---Test 1: Student class---" << endl;
    cout << ">>Calling default constructor, then all mutators," << endl;
    cout << "printing output after each call. Also shows when" << endl;
    cout << "destructor is called." << endl;
    Student student1;
    cout << "Name 0 000-000-0000 0 X classStanding 0" << endl;
    student1.SetName("Katy Perry");
    student1.Print();
    student1.SetID(999899);
    student1.Print();
    student1.SetPhone("949-555-1234");
    student1.Print();
    student1.SetAge(30);
    student1.Print();
    student1.SetGender('F');
    student1.Print();
    student1.SetYear(1);
    student1.Print();
    student1.SetGPA(4);
    student1.Print();
    cout << "---Test 2: CS133Student class---" << endl;
    cout << ">>Calling default constructor, then all mutators," << endl;
    cout << "printing output after each call. Also shows when" << endl;
    cout << "destructor is called." << endl;
    CS133Student student2;
    cout << "Name 0 000-000-0000 0 X classStanding 0" << endl;
    student2.SetName("Tom Brady");
    student2.Print();
    student2.SetID(456789);
    student2.Print();
    student2.SetPhone("714-555-5555");
    student2.Print();
    student2.SetAge(37);
    student2.Print();
    student2.SetGender('M');
    student2.Print();
    student2.SetYear(2);
    student2.Print();
    student2.SetGPA(3.23);
    student2.Print();
    student2.SetScore(500);
    student2.Print();
    student2.SetJava(true);
    student2.Print();
    student2.SetGradDate(5, 12, 2016);
    student2.Print();
    */
    cout << "---Final output---" << endl;
    cout << ">>Creating an array of 7 objects - 4 Students and 3 CS133Students." << endl;
    
    //initialize each Student object
    Student s[4] =
    {
        Student("Katy Perry", 999899, "949-555-1234", 30, 'F', 1, 4),
        Student("Tom Brady", 456789, "714-555-5555", 37, 'M', 2, 3.23),
        Student("Russell Wilson", 876542, "760-703-1234", 26, 'M', 2, 3.8),
        Student("Norm Drapple", 777744, "213-555-6789", 18, 'm', 1, 1.1)
    };
    
    //initialize each CS133Student object
    CS133Student cs[3] =
    {
        CS133Student("Jim Cramer", 668899, "949-665-1234", 63, 'M',1, 3.3, 500, true, 5, 12, 2016),
        CS133Student("Clayton Kershaw", 156789, "248-555-6543", 29, 'M', 2, 2.5, 700, false, 5, 11, 2015),
        CS133Student("Jim Rome", 876545, "703-703-7654", 40, 'M', 2, 3.2, 800, true, 5, 11, 2015)
    };
    cout << endl << ">>Calling printAll() function, passing in each element \n";
    cout << "of the student array. \n\n";
    
    
    /*
    s[0].Print();
    s[1].Print();
    s[2].Print();
    s[3].Print();
    cs[0].Print();
    cs[1].Print();
    cs[2].Print();
    */
    PrintAll(s, 4, cs, 3);
    cout << ">>Deleting all students. \n\n";
}

void PrintAll(Student s[], int sBuff, CS133Student cs[], int csBuff)
{
    for(int i = 0; i < sBuff; ++i)
    {
        s[i].Print();
    }
    for(int i = 0; i < csBuff; ++i)
    {
        cs[i].Print();
    }
}
