#include "box.h"
#include <iostream>
using namespace std;
Box::Box()
{
    x = y = 0;
}

Box::Box(int a, int b)
{
    x = a;
    y = b;
}

inline void Box::getArea()
{
    cout << x * y << endl;
}