#include <iostream>
#include "dynArr.cpp"
using namespace std;
int main()
{
    dynArr<int> arr(5);

    for (int i = 0; i < 5; i++)
    {
        arr.setValue(i, (i + 1) * 10);
    }
    for (int i = 0; i < 5; i++)
    {
        int value = arr.getValue(i);
        cout << value << " ";
    }
    cout << endl;

    arr.allocate(10);
    for (int i = 0; i < 10; i++)
    {
        arr.setValue(i, (i + 1) * 10);
    }
    for (int i = 0; i < 10; i++)
    {
        int value = arr.getValue(i);
        cout << value << " ";
    }
    cout << endl;
}
