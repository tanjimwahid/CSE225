#include <iostream>
using namespace std;

int main()
{

    int *ptr, a = 10;
    // ptr = &a;
    ptr = &a;

    cout << "address of a: " << &a << " Address of ptr: " << ptr << endl;

    return 0;
}