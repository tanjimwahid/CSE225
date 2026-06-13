#include <iostream>
using namespace std;

void SimpleMethod(int n)
{
    int totalPrime = 0;
    for (int i = 2; i <= 100; i++)
    {
        bool isPrime = 1;

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
            }
        }

        if (isPrime)
        {
            cout << i << endl;
            totalPrime++;
        }
    }
    cout << "Total Prime Number: " << totalPrime << endl;
}

void squareRootMethod(int n)
{
    int totalPrime = 0;
    for (int i = 2; i <= 100; i++)
    {
        bool isPrime = true;

        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime == true)
        {
            cout << i << endl;
            totalPrime++;
        }
    }
    cout << "Total Prime Number: " << totalPrime << endl;
}

void sieveErtosthenes(int n)
{
    int limit = 100;

    // Create a raw array of size 101 (so we can safely check index 100)
    bool isPrime[101];

    // Manually set all values to true to start
    for (int i = 0; i <= limit; i++)
    {
        isPrime[i] = true;
    }

    isPrime[0] = false; // 0 is not prime
    isPrime[1] = false; // 1 is not prime

    // Start with the first prime number, 2
    for (int p = 2; p * p <= limit; p++)
    {
        // If p is still marked as prime
        if (isPrime[p] == true)
        {
            // Cross out all multiples of p
            for (int i = p * p; i <= limit; i += p)
            {
                isPrime[i] = false;
            }
        }
    }

    // Print all numbers that survived the crossing-out process
    for (int p = 2; p <= limit; p++)
    {
        if (isPrime[p])
        {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main()
{

    // Sieve of Eratosthenes logic, completely raw
    // SimpleMethod(100);
    // squareRootMethod(100);
}