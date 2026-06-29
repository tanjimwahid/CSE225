#include <iostream>
using namespace std;

// pass by value
void changeInt(int x)
{
    x = 20;
}

// pass by reference
void changeValue(intd *ptr)
{
    *ptr = 20;
}

int main()
{

    int a = 10;
    changeInt(a);
    cout << "Value of a: " << a << "\n";

    int b = 10;
    changeValue(&b);
    cout << "Value of b: " << b << endl;
    return 0;
}