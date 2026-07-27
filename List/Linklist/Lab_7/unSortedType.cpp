#include "unSortedType.h"
#include <iostream>
using namespace std;

template <class T>
UnsortedType<T>::UnsortedType()
{
    head = tail = pointTo = NULL;
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
        head = tail = newNode;
        size++;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        size++;
    }
}

template <class T>
void UnsortedType<T>::Search(T value, bool &found)
{
    found = false;
    Node *temp = head;
    while (temp != NULL)
    {
        if (value == temp->data)
        {
            value = temp->data;
            found = true;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }

    cout << "Not found Error: " << endl;
}

template <class T>
void UnsortedType<T>::MakeEmpty()
{

    Node *temp = head;

    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = pointTo = tail = NULL;
    size = 0;
}

template <class T>
UnsortedType<T>::~UnsortedType()
{
    MakeEmpty();
}

template <class T>
void UnsortedType<T>::Delete(T value)
{
    if (head == NULL)
    {
        cout << "Not found Error: " << endl;
        return;
    }

    if (head->data == value)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
        return;
    }

    Node *prev = head;
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            prev->next = temp->next;
            delete temp;
            size--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Not found Error: " << endl;
}

template <class T>
void UnsortedType<T>::GetNext(T &value)
{
    if (pointTo == NULL)
    {
        pointTo = head;
        value = pointTo->data;
    }
    else
    {
        value = pointTo->data;
    }
    pointTo = pointTo->next;
}
template <class T>
void UnsortedType<T>::Reset()
{
    pointTo = NULL;
}