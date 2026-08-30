#include <iostream>
#include "queuetype.cpp"
using namespace std;

int main()
{
    QueueType<string> ch;

    ch.Enqueue("1");

    cout << "Enter the number of binary: " << endl;
    int n;
    cin >> n;
    string value;
    for (int i = 0; i < n; i++)
    {
        ch.Dequeue(value);
        cout << value << endl;
        ch.Enqueue(value + "0");
        ch.Enqueue(value + "1");
    }

    return 0;
}