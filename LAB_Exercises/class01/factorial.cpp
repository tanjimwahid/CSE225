#include <iostream>
using namespace std;

int main()
{

    int a;
    cout << "Input Number ";
    cin >> a;
    int fact = 1;
    for (int i = 1; i <= a; i++)
    {
        fact *= i;
    }
    cout << "Factorial " << fact;
    return 0;
}