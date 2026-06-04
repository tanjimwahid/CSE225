#include <iostream>
using namespace std;

int main()
{
    // Implicit Type Conversion
    int num1 = 10;
    double num2 = num1; // int -> double

    cout << "Implicit Conversion:" << endl;
    cout << "Integer value: 10/3 = " << 10 / 3 << endl;
    cout << "Converted to double: 10/3.0 = " << 10 / 3.0 << endl;

    // Explicit Type Conversion (Type Casting)
    double price = 99.99;
    int roundedPrice = (int)price; // double -> int

    cout << "\nExplicit Conversion:" << endl;
    cout << "Double value: " << price << endl;
    cout << "Converted to int: " << roundedPrice << endl;

    return 0;
}
