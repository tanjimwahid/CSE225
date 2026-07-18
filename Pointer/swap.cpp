#include <iostream>
using namespace std;

// pass by value
void changeInt(int x)
{
    x = 20;
}

// pass by pointer
void changeValue(int *ptr)
{
    *ptr = 20;
}

// change by reference
void changeRef(int &a)
{
    a = 30;
}

int main()
{

    int a = 10;
    changeInt(a);
    cout << "Value of a: " << a << "\n";

    int b = 10;
    changeValue(&b);
    cout << "Value of b: " << b << endl;

    int c = 10;
    changeRef(c);
    cout << "Value of c: " << c << endl;

    return 0;
}