#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
  int n = 1;
  IntBinaryTree<int> tree = IntBinaryTree<int>();

  while(n >= 0){
    cout << "Please enter integers to insert into binary tree (-1 to stop): ";
    cin >> n;
    if(n > 0)
      tree.insertNode(n);
  }
  tree.displayInOrder();
  cout << endl;
  cout << "Please enter an integer to find it's successor (-1 to stop): ";
  cin >> n;
  tree.FindSuccessor(n);
  return 0;
}
