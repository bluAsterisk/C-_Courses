//
//  main.cpp
//  assignment09
//
//  Created by ケビン・ファン on 3/18/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>
#include "Patient.h"
#include "PatientComparison.h"
#include "PriorityQueue.h"
#include "QueueEmpty.h"
#include <iomanip>

using namespace std;

int main()
{
    try
    {
        PriorityQueue<Patient, PatientComparison> pq;
        // initialize array of queues
        Patient p[7] =
        {
            Patient("Alice Ailment", 3),
            Patient("Irene Ill", 1),
            Patient("Sid Sickly", 4),
            Patient("Cathy Coughing", 5),
            Patient("Bob Bleeding", 2),
            Patient("Frank Feelingbad", 7),
            Patient("Sam Sneezing", 5),
        };
        for(int i = 0; i < 7; ++i)
        {
            pq.enqueue(p[i]);
        }
        int hour = 0;
        int min = 0;
        int time = 0;
        bool pqEmpty = false;
        while(!pq.isEmpty())
        {
            if(min == 59)
            {
                min = 0;
                ++hour;
            }
            else
            {
                ++min;
            }
            ++time;
            if(time == 30)
            {
                cout << "-- Finished treating" << pq.peek().getName() <<
                " at " << hour << ": " << setfill('0') <<
                setw(2) << min << endl << endl;
                pq.dequeue();
                time = 0;
                if(pq.isEmpty())
                {
                    pqEmpty = true;
                }
            }
            if(hour == 1 && min == 30)
            {
                pq.enqueue(Patient("Paul Pain", 0, true));
                cout << "-- Finished treating" << pq.peek().getName() <<
                " at " << hour << ": " << setfill('0') <<
                setw(2) << min << endl << endl;
                pq.dequeue();
                time = 0;
            }
            if(hour == 2 && min == 10)
            {
                pq.enqueue("Tom Temperature", 0, true);
                cout << "-- Finished treating" << pq.peek().getName() <<
                " at " << hour << ": " << setfill('0') <<
                setw(2) << min << endl << endl;
                pq.dequeue();
                time = 0;
            }
        }
    }
    catch(QueueEmpty qe)
    {
        cout << ge.what() << endl;
    }
}