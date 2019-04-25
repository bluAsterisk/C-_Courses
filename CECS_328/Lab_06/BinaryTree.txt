#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

#include <iostream>
#include <iomanip>

using namespace std;

template <class T> struct TreeNode
{
    T value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

template <class T>
class IntBinaryTree{
private:
    TreeNode<T>* root;

    void insert(TreeNode<T> *&, TreeNode<T> *&);
    void destroySubTree(TreeNode<T> *);
    void deleteNode(T, TreeNode<T> *&);
    void makeDeletion(TreeNode<T> *&);
    void displayInOrder(TreeNode<T> *) const;
    void displayPreOrder(TreeNode<T> *) const;
    void displayPostOrder(TreeNode<T> *) const;
    int leaf_count(T);
    int non_leaf_count(T);
public:
    //Constructor
    IntBinaryTree(){ root = NULL;}

    ~IntBinaryTree(){destroySubTree(root);}

    //Binary Tree Operations
    void insertNode(T);
    bool searchNode(T);
    void remove(T);
    void FindSuccessor(T);

    void displayInOrder() const{ displayInOrder(root);}
    void displayPreOrder() const{ displayPreOrder(root);}
    void displayPostOrder() const{ displayPostOrder(root);}
    int leaf_count() {non_leaf_count(root);}
    int non_leaf_count() {non_leaf_count(root);}
    int size();
};

template <class T>
void IntBinaryTree<T>::insertNode(T num){
    TreeNode<T> *newNode = new TreeNode<T>;

    newNode->value = num;
    newNode->left = newNode->right = newNode->parent = NULL;

    //Insert the Node
    insert(root, newNode);
}

template <class T>
void IntBinaryTree<T>::insert(TreeNode<T> *&nodePtr, TreeNode<T> *&newNode){
    if(nodePtr == NULL)
      nodePtr = newNode; // point current node to new node
    else if(newNode->value < nodePtr->value) // connect parent if NULL, traverse left
    {
      if(nodePtr->left == NULL)
        newNode->parent = nodePtr;
      insert(nodePtr->left, newNode);
    }
    else
    {
      if(nodePtr->right == NULL)// connect parent if NULL, traverse right
        newNode->parent = nodePtr;
      insert(nodePtr->right, newNode);
    }
}

template <class T>
void IntBinaryTree<T>::displayInOrder(TreeNode<T> *nodePtr) const{
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

template <class T>
void IntBinaryTree<T>::displayPreOrder(TreeNode<T> *nodePtr) const{
    if(nodePtr){
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template <class T>
void IntBinaryTree<T>::displayPostOrder(TreeNode<T> *nodePtr) const{
    if(nodePtr){
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

template <class T>
void IntBinaryTree<T>::destroySubTree(TreeNode<T> *nodePtr){
    cout << "Binary Tree Destroyed\n";
}

template <class T>
bool IntBinaryTree<T>::searchNode(T num){
    TreeNode<T>* nodePtr = root;

    while(nodePtr){
        if (nodePtr->value == num)
        {
            cout << num.GetName();
            return true;
        }
        else if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    cout << "Employee not found..." << endl;
    return false;
}

template <class T>
void IntBinaryTree<T>::remove(T num){
    deleteNode(num, root);
}

template <class T>
void IntBinaryTree<T>::FindSuccessor(T num){
  TreeNode<T>* nodePtr = root;
  //cout << nodePtr->right->parent->value;
  while(nodePtr){
      if (nodePtr->value == num) // if value is found, display the successor
      {
          // first go right, then far left
          if(nodePtr->right != NULL)
          {
            nodePtr = nodePtr->right;
            while(nodePtr->left != NULL)
              nodePtr = nodePtr->left;
            cout << num << "'s successor is " << nodePtr->value << endl;
            break;
          }
          else if(nodePtr->right == NULL)
          {
            while(num >= nodePtr->parent->value) // check parents if num is greater
                nodePtr = nodePtr->parent;
              cout << num << "'s successor is " << nodePtr->parent->value << endl;
              break;
          }
          else
            {
              cout << "Successor not found..." << endl;
              break;
            }
      }
      else if (num < nodePtr->value) // find the num going left
          nodePtr = nodePtr->left;
      else
          nodePtr = nodePtr->right; // find the num going right
  }
}

template <class T>
void IntBinaryTree<T>::deleteNode(T num, TreeNode<T> *&nodePtr){
    if (num < nodePtr->value)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

template <class T>
void IntBinaryTree<T>::makeDeletion(TreeNode<T> *&nodePtr){
    TreeNode<T> *tempNodePtr;

    if (nodePtr == NULL)
        cout << "Cannot delete empty node\n";
    else if(nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if(nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    //If the node has two Children
    else
    {
        //Move one node to the right
        tempNodePtr = nodePtr->right;
        //Go to the end left node
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        //Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        //Reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

template <class T>
int IntBinaryTree<T>::leaf_count(T nodePtr) // child nodes
{
    if(nodePtr == NULL)
        return 0;
    else if (nodePtr->left == NULL && nodePtr->right == NULL)
        return 1;
    else
        return leaf_count(nodePtr->left) + leaf_count(nodePtr->right);
}

template <class T>
int IntBinaryTree<T>::non_leaf_count(T nodePtr) // parent nodes
{
    if(nodePtr == NULL)
        return 0;
    else if (nodePtr->left != NULL || nodePtr->right != NULL)
        return 1;
    else
        return leaf_count(nodePtr->left) + leaf_count(nodePtr->right);
}

template <class T>
int IntBinaryTree<T>::size()
{
    return leaf_count() + non_leaf_count();
}
#endif
