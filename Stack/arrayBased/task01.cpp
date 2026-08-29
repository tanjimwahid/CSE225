#include "stacktype.cpp"
#include <iostream>
#include <string>
using namespace std;

// template <class T>

void chekEmpty(bool exp)
{
    if (exp)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is not Empty" << endl;
    }
}
void checkFull(bool exp)
{
    if (exp)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        cout << "Stack is not Full" << endl;
    }
}

void PrintStack(StackType<int> &data)
{
    int arr[5];
    int i = -1;
    while (!data.isEmpty())
    {
        i++;
        arr[i] = data.top();
        data.pop();
    }
    for (int x = i; x >= 0; x--)
    {
        cout << arr[x] << " ";
        data.push(arr[x]);
    }

    cout << endl;
}
int main()
{

    StackType<int> num;
    chekEmpty(num.isEmpty());
    num.push(5);
    num.push(7);
    num.push(4);
    num.push(2);
    chekEmpty(num.isEmpty());
    checkFull(num.isFull());
    num.push(3);
    PrintStack(num);
    PrintStack(num);
    checkFull(num.isFull());
    chekEmpty(num.isEmpty());
    num.pop();
    num.pop();
    PrintStack(num);

    return 0;
}
