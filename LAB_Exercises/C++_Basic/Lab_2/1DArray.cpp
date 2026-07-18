#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int *ptr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> ptr[i];

    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";
    cout << endl;
    delete ptr;
}