// Write a function isPrime(int n) that checks if ‘n’ is a prime number. Use this function to print all the
// prime numbers between 300 and 500.

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    bool isPrime = true;

    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main()
{
    int a, b;
    cout << "Enter 2 Numbers Sir: ";
    cin >> a >> b;

    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;

    cout << "MAX: " << max << " MIN: " << min << endl;
    for (int i = min; i <= max; i++)
    {
        if (isPrime(i))
        {
            cout << "Prime Number :" << i << endl;
        }
    }

    return 0;
}
