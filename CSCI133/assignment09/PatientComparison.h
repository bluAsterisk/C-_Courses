//
//  PatientComparison.h
//  assignment09
//
//  Created by ケビン・ファン on 3/18/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef assignment09_PatientComparison_h
#define assignment09_PatientComparison_h

#include "Patient.h"

class PatientComparison
{
public:
    bool operator()(Patient p1, Patient p2);
};

bool PatientComparison:: operator() (Patient p1, Patient p2)
{
    if(p1.isLifeThreatening())
    {
        return true;
    }
    else if(p2.isLifeThreatening())
    {
        if(p1.getWaitTime() > p2.getWaitTime())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

#endif
