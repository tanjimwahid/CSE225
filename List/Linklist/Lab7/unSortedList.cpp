#include "unSortedList.h"
#include <iostream>
using namespace std;

template <class T>
UnsortedType<T>::UnsortedType()
{
    head = NULL;
    pointTo = NULL;
    size = 0;
}

template <class T>
int UnsortedType<T>::Length()
{
    return size;
}

template <class T>
void UnsortedType<T>::Insert(T value)
{

    Node *newNode = new Node;
    newNode->data = value;

    if (head == NULL)
    {
        head = pointTo = newNode;
        // head->data =
    }
    else
    {
        Node *temp = head;
        head->next = newNode;
        head->data = value;
        newNode->next = temp;
    }
}

template <class T>
void UnsortedType<T>::Print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << head->data << " -> ";
        temp->next = head->next;
    }
}
