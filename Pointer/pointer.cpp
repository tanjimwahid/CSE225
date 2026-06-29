#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    cout << "&a : " << &a << endl;
    int *ptr = &a;
    cout << "*ptr : " << *ptr << endl;
    cout << "ptr : " << ptr << endl;

    int *num = new int;
    cout << "Value of *ptr : " << sizeof(*num) << endl;
    cout << "Value of ptr : " << sizeof(num) << endl;
    return 0;
}