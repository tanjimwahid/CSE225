#include <iostream>
using namespace std;

int main()
{

    cout << "Hello World" << endl;

    int x = 8, y = 10;
    int *ptr1 = new int;
    *ptr1 = 8;
    int *ptr2 = new int;
    *ptr2 = 10;
    ptr2 = ptr1;
    delete ptr1;
    cout << ptr2 << endl;
    cout << ptr1 << endl;
}