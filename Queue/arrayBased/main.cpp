#include <iostream>

#include "queuetype.cpp"
using namespace std;
/*
template <class T>
void printQueue(QueueType<T> &q)
{
    vector<T> temp;
    T val;

    while (!q.IsEmpty())
    {
        q.Dequeue(val);
        temp.push_back(val);
    }

    for (size_t i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
        if (i != temp.size() - 1)
            cout << ", ";
    }
    cout << endl;

    for (size_t i = 0; i < temp.size(); i++)
        q.Enqueue(temp[i]);
}
*/
int main()
{
    /*
    QueueType<int> q(5);

    cout << (q.IsEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;

    q.Enqueue(5);
    q.Enqueue(7);
    q.Enqueue(4);
    q.Enqueue(2);

    cout << (q.IsEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
    cout << (q.IsFull() ? "Queue is Full" : "Queue is not full") << endl;

    q.Enqueue(6);

    printQueue(q);

    cout << (q.IsFull() ? "Queue is Full" : "Queue is not full") << endl;

    if (q.IsFull())
        cout << "Queue Overflow" << endl;
    else
        q.Enqueue(8);

    int x;
    q.Dequeue(x);
    q.Dequeue(x);

    printQueue(q);

    q.Dequeue(x);
    q.Dequeue(x);
    q.Dequeue(x);

    cout << (q.IsEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;

    if (q.IsEmpty())
        cout << "Queue Underflow" << endl;
    else
        q.Dequeue(x);
*/
    cout << "Task 2" << endl;
    int n;
    cout << "Enter n" << endl;
    cin >> n;
    QueueType<string> q(n + 5);

    q.Enqueue("1");

    for (int i = 0; i < n; i++)
    {
        string value;
        q.Dequeue(value);
        cout << value << endl;

        q.Enqueue(value + "0");
        q.Enqueue(value + "1");
    }

    return 0;
}