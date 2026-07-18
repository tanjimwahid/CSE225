#include <iostream>
#ifndef BOX_H
#define BOX_H

class Box
{
private:
    int x, y;

public:
    Box();
    Box(int x, int y);
    void getArea();
};

#endif