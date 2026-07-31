#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    Complex c1(3, 2);
    Complex c2(1, 4);
    Complex c3;

    c3 = c1 + c2;
    cout << "c1 + c2 -> ";
    c3.Print();
    c3 = c1 - c2;
    cout << "c1 - c2 -> ";
    c3.Print();
    c3 = c1 * c2;
    cout << "c1 * c2 -> ";
    c3.Print();
    c3 = c1 / c2;
    cout << "c1 / c2 -> ";
    c3.Print();

    if (c1 != c2)
        cout << "c1 != c2 is true" << endl;
    if (c1 == c1)
        cout << "c1 == c1 is true" << endl;
    if (c1 < c2)
        cout << "c1 <  c2 is true" << endl;
    if (c2 > c1)
        cout << "c2 >  c1 is true" << endl;
    if (c1 <= c2)
        cout << "c1 <= c2 is true" << endl;
    if (c2 >= c1)
        cout << "c2 >= c1 is true" << endl;

    return 0;
}