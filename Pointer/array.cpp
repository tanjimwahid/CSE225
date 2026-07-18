#include <iostream>
using namespace std;

int main()
{

    char str[6] = "Hello";
    char *ptr = str;
    int x = 0;
    cout << ptr[2] << endl;
    while (x < 6)
    {
        cout << *ptr << endl;
        ptr++;
        x++;
    }

    return 0;
}