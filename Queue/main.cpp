#include "queuetype.cpp"
#include <iostream>
using namespace std;

void printQueue(QueueType<int> &testQ)
{

    int arr[5];
    int value;

    for (int i = 0; i < 5; i++)
    {
        testQ.Dequeue(value);
        arr[i] = value;
        cout << value << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        testQ.Enqueue(arr[i]);
        // arr[i] = value;
    }
}

int sumOfDigits(int x)
{
    if (x <= 1)
        return 1;
    return x + sumOfDigits(x - 1);
}
int DecToBin(int dec)
{
    if (dec == 0)
        return 0;
    return (dec % 2) + 10 * DecToBin(dec / 2);
}

int main()
{
    QueueType<int> q1;
    // 5, 7, 4, 2, 6
    q1.Enqueue(5);
    q1.Enqueue(7);
    q1.Enqueue(4);
    q1.Enqueue(2);
    q1.Enqueue(6);
    printQueue(q1);
    printQueue(q1);

    int sum = sumOfDigits(4);
    cout << sum << endl;

    int bin = DecToBin(10);
    cout << bin << endl;

    return 0;
}