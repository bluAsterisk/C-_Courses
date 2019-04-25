//
//  PriorityQueue.h
//  assignment09
//
//  Created by ケビン・ファン on 3/18/16.
//  Copyright (c) 2016 ケビン・ファン. All rights reserved.
//

#ifndef assignment09_PriorityQueue_h
#define assignment09_PriorityQueue_h

#include "QueueEmpty.h"

template<typename E>
struct Node{
    E data;
    Node *next;
    Node( E data ) : data(data), next(0) {}
};

template <typename E, typename C>               // element and comparator
class PriorityQueue {                           // priority-queue interface
public:
    PriorityQueue<E, C>::PriorityQueue()                                // default constructor
    {
            front = NULL;
            back = NULL;

    }
    PriorityQueue<E, C>::PriorityQueue(const PriorityQueue& source)     //copy constructor
    {
        if(source.front == NULL) // empty queue
        {
            front = NULL;
            back = NULL;
            
        }
        else if(source.front == source.back) // one queue
        {
            Node<E> *newNode;
            front = newNode;
            back = newNode;
            newNode->data = source.front->data;
            newNode->next = NULL;
        }
        else // more than one item in queue
        {
            Node<E> *temp;
            temp = new Node<E>;
            front = temp;
            back = temp;
            temp->data = source.front->data;
            temp->next = NULL;
            Node<E> *newNode;
            newNode = source.front->next;
            while(newNode != NULL)
            {
                Node<E> = *temp;
                temp = new Node<E>;
                temp->next = NULL;
                temp->data = newNode->data;
                back->next = temp;
                back = temp;
            }
        }
    }
    
    void operator=( const PriorityQueue& source );  // overloaded assignment operator
    ~PriorityQueue();                               // destructor
    bool isEmpty() const;                           // is the queue empty?
    void enqueue(const E& e);                       // insert element
    const E& peek() const throw(QueueEmpty);        // minimum element
    void dequeue() throw(QueueEmpty);               // remove element
private:
    Node<E> *front;
    Node<E> *back;
};

template <typename E, typename C>
PriorityQueue & PriorityQueue::operator= (const PriorityQueue& source)
{
    if(this != &source)
    {
        if(source.front == NULL) // empty queue
        {
            front = NULL;
            back = NULL;
            
        }
        else if(source.front == source.back) // one queue
        {
            Node<E> *newNode;
            front = newNode;
            back = newNode;
            newNode->data = source.front->data;
            newNode->next = NULL;
        }
        else // more than one item in queue
        {
            Node<E> *temp;
            temp = new Node<E>;
            front = temp;
            back = temp;
            temp->data = source.front->data;
            temp->next = NULL;
            Node<E> *newNode;
            newNode = source.front->next;
            while(newNode != NULL)
            {
                Node<E> = *temp;
                temp = new Node<E>;
                temp->next = NULL;
                temp->data = newNode->data;
                back->next = temp;
                back = temp;
            }
        }
    }
    return *this;
}


template <typename E, typename C>
bool PriorityQueue<E, C>::isEmpty() const
{
    if(front == NULL)
        return true;
}

template <typename E, typename C>
void PriorityQueue<E, C>::enqueue(const E& e)
{
    Node<E> *temp;
    C comp;
    if(back == NULL) // if queue is empty
    {
        temp = new Node<E>(e);
        back = temp;
        front = temp;
    }
    else if(front == back) // one queue
    {
        temp = new Node<E>(e);
        temp->next = back->next;
        back = temp;
        front->next = temp;
    }
    else //if more than one item in list
    {
        if(comp(e,front->data))
        {
            temp = new Node<E>(e);
            temp->next = front;
            front = temp;
        }
        else if(comp(e,back->data))
        {
            Node<E> *curr;
            curr1 = front->next;
            while(curr->next != NULL)
            {
                if(comp(e,curr->next->data))
                {
                    temp = new Node<E>(e);
                    temp->next = curr->next;
                    curr->next = temp;
                    break;
                }
                curr = curr->next;
            }
        }
        else
        {
            temp = new Node<E>(e);
            temp->next = back->next;
            back->next = temp;
            back = temp;
        }
    }
}

template <typename E, typename C>
const E& PriorityQueue<E, C>::peek() const throw(QueueEmpty)
{
    try
    {
        if(isEmpty())
        {
            throw(QueueEmpty("Unable to peek, queue is empty..."));
        }
        catch(QueueEmpty qe)
        {
            throw;
        }
    }
}

template <typename E, typename C>
void PriorityQueue<E, C>::dequeue() throw(QueueEmpty)
{
    try
    {
        if(isEmpty())
        {
            throw(QueueEmpty("Unable to peek, queue is empty..."));
        }
        else if(front == back)
        {
            delete front;
            front = NULL;
            back = NULL;
        }
        else
        {
            Node<E> *temp;
            temp = front;
            front = front->next;
            delete temp;
        }
    }
}

#endif
