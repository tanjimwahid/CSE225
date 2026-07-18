#include <iostream>
#include "chArray.h"
using namespace std;

chArray::chArray()
{
    size = 10;
    arr = new char[size];
    index = 0;
}

chArray::chArray(char c, int sz)
{
    size = sz;
    arr = new char[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = c;
    }
    index = size;
}

void chArray::outputstr()
{
    for (int i = 0; i < index; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void chArray::inputStr(char c)
{
    arr[index] = c;
    index++;
}
