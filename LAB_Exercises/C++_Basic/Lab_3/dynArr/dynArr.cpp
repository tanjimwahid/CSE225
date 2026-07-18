#include "dynArr.h"
#include <iostream>
using namespace std;

template <class T>
dynArr<T>::dynArr()
{
    data = NULL;
    this->size = 0;
}

// dynArr(int s);

template <class T>
dynArr<T>::dynArr(int s)
{
    this->size = s;
    this->data = new T[s];
}

template <class T>
dynArr<T>::~dynArr()
{
    delete[] data;
    data = NULL;
    this->size = -1;
}

template <class T>
void dynArr<T>::setValue(int index, int value)
{
    this->data[index] = value;
}
template <class T>
T dynArr<T>::getValue(int index)
{
    return this->data[index];
}

template <class T>
void dynArr<T>::allocate(int s)
{
    this->size = s;
    delete[] data;
    data = new T[s];
}