//
//  Patient.h
//  assignment09
//
//  Created by ケビン・ファン on 3/18/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef assignment09_Patient_h
#define assignment09_Patient_h

#include <string>
#include <cstring>
using namespace std;

class Patient{
private:
    string name;
    int waitTime;
    bool lifeThreatening;
public:
    Patient(string n, int w) 			//constructor that gets passed in the name and waitTime, lifeThreatening defaults to false
    {
        name = n;
        waitTime = w;
        lifeThreatening = false;
    }
    Patient(string n, int tm, bool lt)	//constructor that gets passed in the name and waitTime and lifeThreatening
    {
        name = n;
        waitTime = tm;
        lifeThreatening = lt;
    }
    int getWaitTime(); 					//returns waitTime
    string getName()const; 				//return name
    bool isLifeThreatening();           //returns the value of is lifeThreatening
    void display() const; 				//displays name waitTime and lifeThreatening each separated by a space
};

int Patient::getWaitTime()
{
    return waitTime;
}

string Patient::getName() const
{
    return name;
}

bool Patient::isLifeThreatening()
{
    return lifeThreatening;
}

void Patient::display() const
{
    cout << name << " " << waitTime << " " << lifeThreatening << endl;
}

#endif
