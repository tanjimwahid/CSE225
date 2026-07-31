#include <iostream>
using namespace std;
int main()
{
    char str[5] = {'H', 'E', 'L', 'L', 'O'};
    char *ptr = &str[0];

    for (int i = 0; i < 5; i++)
    {
        cout << *(ptr + i);
    }
    cout << "\n";

    cout << "ptr = " << &ptr << endl;
    cout << "str = " << &str[0] << endl;

    return 0;
}