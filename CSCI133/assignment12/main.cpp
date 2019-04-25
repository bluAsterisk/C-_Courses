//
//  main.cpp
//  assignment12
//
//  Created by ケビン・ファン on 5/1/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"
#include "EmployeeInfo.h"
#include <vector>
using namespace std;

int main()
{
    IntBinaryTree<EmployeeInfo> tree = IntBinaryTree<EmployeeInfo>();
    EmployeeInfo eInfo[8] =
    {
    eInfo[0] = EmployeeInfo("John Williams", 1021),
    eInfo[1] = EmployeeInfo("Bill Witherspoon", 1057),
    eInfo[2] = EmployeeInfo("Jennifer Twain", 2487),
    eInfo[3] = EmployeeInfo("Sofia Lancaster", 3769),
    eInfo[4] = EmployeeInfo("Debbie Reece", 1017),
    eInfo[5] = EmployeeInfo("George McMullen", 1275),
    eInfo[6] = EmployeeInfo("Ashley Smith", 1899),
    eInfo[7] = EmployeeInfo("Josh Plemmons", 4218)
    };
    for(int i = 0; i < 7; ++i)
    {
        tree.insertNode(eInfo[i]);
    }
    EmployeeInfo *temp;
    int choice;
    string EmpName;
    int EmpID;
    do
    {
        cout << "1: Insert | 2: Search | 3: Remove" << endl;
        cout << "4: Display In­Order | 5: Display Pre­Order | 6: Display Post­Order" << endl;
        cout << "7: Leaf Count | 8: Non­Leaf Count | 9: Size" << endl;
        cout << "10: Show Front | 11: Show Menu | 0: Quit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Input employee name: ";
            cin >> EmpName;
            cout << "Input employee number:";
            cin >> EmpID;
            tree.insertNode(EmployeeInfo(EmpName, EmpID));
            break;
        case 2:
            cout << "Input employee number: ";
            cin >> EmpID;
            temp->SetID(EmpID);
            tree.searchNode(*temp);
            break;
        case 3:
            cout << "Input employee number: ";
            cin >> EmpID;
            temp->SetID(EmpID);
            tree.remove(*temp);
            break;
        case 4:
            tree.displayInOrder();
            break;
        case 5:
            tree.displayPreOrder();
            break;
        case 6:
            tree.displayPostOrder();
            break;
        case 7:
            tree.leaf_count();
            break;
        case 8:
            tree.non_leaf_count();
            break;
        case 9:
            tree.size();
            break;
        case 10:
            break;
        case 11:
            cout << "1: Insert | 2: Search | 3: Remove" << endl;
            cout << "4: Display In­Order | 5: Display Pre­Order | 6: Display Post­Order" << endl;
            cout << "7: Leaf Count | 8: Non­Leaf Count | 9: Size" << endl;
            cout << "10: Show Front | 11: Show Menu | 0: Quit" << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }while(choice);
}
