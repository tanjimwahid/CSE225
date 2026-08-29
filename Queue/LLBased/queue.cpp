#include "queue.h"
#include <iostream>
using namespace std;

template <class T>
Queue<T>::Queue()
{
    front = rear = NULL;
}
template <class T>
void Queue<T>::makeEmpty()
{
    NodeType *temptr;
    while (front != NULL)
    {
        temptr = front;
        front = front->next;
        delete temptr;
    }
    rear = NULL;
}

template <class T>
Queue<T>::~Queue()
{
    makeEmpty();
}

template <class T>
bool Queue<T>::isEmpty()
{
    return front == NULL;
}

template <class T>
void Queue<T>::enQueue(T data)
{
    try
    {
        NodeType *newNode = new NodeType;
        newNode->data = data;
        newNode->next = NULL;
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    catch (bad_alloc exception)
    {
        cout << "Enqueue is not possible" << endl;
    }
}

template <class T>
void Queue<T>::deQueue(T &data)
{
    try
    {
        NodeType *newNode = front;
        data = front->data;
        front = front->next;
    }
    catch (bad_alloc exception)
    {
        cout << "Dequeue is not possible" << endl;
    }
}

template <class T>
T Queue<T>::frontValue()
{
    try
    {
        if (isEmpty())
            throw EmptyQueue();
        return front->data;
    }
    catch (EmptyQueue)
    {
        cout << "Queue is empty!" << endl;
        return T();
    }
}