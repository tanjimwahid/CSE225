#include <iostream>
using namespace std;

int main()
{

    int x = 10;
    int *ptr = &x;
    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << "ptr == &x : " << (ptr == &x) << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << "*&x: " << *&x << endl;

    // Reference Variables
    int &ref = x;
    cout << "ref: " << ref << endl;
    cout << "&ref: " << &ref << endl;

    return 0;
}