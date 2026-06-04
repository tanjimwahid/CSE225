#include <iostream>
using namespace std;

int main()
{

    int a = 3;
    int b = a++;

    cout << "value of a: " << a << endl;
    cout << "value of b after b = a++: " << b << endl;

    int x = 3;
    int y = ++x;

    cout << "Value of x: " << x << endl;
    cout << "Value of Y: " << y << endl;

    // int i;
    // for (i = 1; i <= 1000; i++)
    // {
    //     cout << "i: " << i << endl;
    // }

    return 0;
}