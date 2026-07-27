#include "unSortedType.h"
#include <iostream>
using namespace std;

template <class T>
UnsortedType<T>::UnsortedType()
{
    currentSize = 0;
    pointTo = -1;
    data = new T[SIZE];
}

template <class T>
UnsortedType<T>::~UnsortedType()
{
    currentSize = 0;
    pointTo = -1;
    delete data;
    data = NULL;
}

template <class T>
int UnsortedType<T>::Length()
{
    return currentSize;
}

template <class T>
bool UnsortedType<T>::IsFull()
{
    return currentSize == SIZE;
}
template <class T>
void UnsortedType<T>::MakeEmpty()
{
    pointTo = -1;
    currentSize = 0;
}

template <class T>
void UnsortedType<T>::Insert(T value)
{
    if (IsFull())
    {
        cout << "FUll" << endl;
        return;
    }
    data[currentSize] = value;
    currentSize++;
}

template <class T>
void UnsortedType<T>::Search(T value, bool &found)
{
    found = false;

    for (int i = 0; i < currentSize; i++)
    {
        if (data[i] == value)
        {
            found = true;
            break;
        }
    }
}

template <class T>
void UnsortedType<T>::Delete(T value)
{
    bool found = false;
    int key = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (data[i] == value)
        {
            found = true;
            break;
        }
        key++;
    }

    if (found)
    {
        data[key] = data[currentSize - 1];
    }
}

template <class T>
void UnsortedType<T>::GetNext(T &value)
{

    value = data[pointTo++];
}

template <class T>
void UnsortedType<T>::Reset()
{

    pointTo = -1;
}
