#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, length;

    // default constructor
    Rectangle()
    {
        width = length = 0;
    }

    // constructor with initializers
    Rectangle(int w, int l)
    {
        width = w;
        length = l;
    }

    // copy constructor
    Rectangle(const Rectangle &r)
    {
        width = r.width;
        length = r.length;
    }

    ~Rectangle()
    {
        cout << "INSIDE Destructore" << endl;
    }
};

void print(Rectangle r)
{
    cout << r.width << " " << r.length << endl;
}

Rectangle create(int w, int l)
{
    Rectangle r;
    r.width = w;
    r.length = l;
    return r;
}

int main()
{
    Rectangle r1;       // default constructor is called
    Rectangle r2(5, 3); // constructor with initializers is called
    Rectangle r3 = r2;  // copy constructor is called: r3.Rectangle(r2)
    Rectangle r4(r3);
    print(r3);
    print(r4);                  // copy constructor called again (passing by value): Rectangle r = r3
    Rectangle t = create(4, 2); // copy constructor called: Rectangle t = r (the returned object)
    print(t);
    return 0;
}