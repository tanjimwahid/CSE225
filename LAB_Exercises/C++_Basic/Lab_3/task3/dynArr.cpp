#include "dynArr.h"
#include <iostream>
using namespace std;
dynArr::dynArr()
{
    data = NULL;
    size = 0;
}
dynArr::dynArr(int s)
{
    row = col = s;
    data = new int *[row];
    for (int i = 0; i < row; i++)
    {
        data[i] = new int[col];
    }
    size = s;
}
dynArr::~dynArr()
{
    delete[] data;
}
int dynArr::getValue(int index)
{
    return data[index];
}
void dynArr::setValue(int index, int value)
{
    data[index] = value;
}