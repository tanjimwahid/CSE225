#include <iostream>
using namespace std;

int main()
{
    cout << (bool)100 + (bool)5 << endl;
    // Output: 2
    cout << (bool)5 + 3 << endl;
    // Output: 4
    cout << 23.5 + 2 + 'A' << endl;
    // Output: 90.5

    char alph = 65;
    cout << alph << endl;
    return 0;
}