#include "stacktype.h"
#include <iostream>

using namespace std;

template <class T>
StackType<T>::StackType()
{
    data = new T[SIZE];
    topIndex = -1;
}

template <class T>
StackType<T>::~StackType()
{
    delete[] data;
}

template <class T>
bool StackType<T>::isFull()
{
    return (topIndex == (SIZE - 1));
}

template <class T>
bool StackType<T>::isEmpty()
{
    return (topIndex == -1);
}

template <class T>
void StackType<T>::makeEmpty()
{
    topIndex = 0;
}

template <class T>
void StackType<T>::push(T value)
{
    try
    {
        if (isFull())
        {
            throw FullStack;
        }
        else
        {
            topIndex++;
            data[topIndex] = value;
        }
    }
    catch (FullStack e)
    {
        cout << "Stack is FULL" << endl;
    }
}

template <class T>
void StackType<T>::pop()
{
    try
    {
        if (isEmpty())
            throw EmptyStack;
        else
        {
            topIndex--;
        }
    }
    catch (EmptyStack e)
    {
        cout << "Stack is Empty" << endl;
    }
}

template <class T>
T StackType<T>::top()
{
    try
    {
        if (isEmpty())
            throw EmptyStack;
        else
        {
            return data[topIndex];
        }
    }
    catch (EmptyStack e)
    {
        cout << "Stack is Empty" << endl;
        return T();
    }
}
