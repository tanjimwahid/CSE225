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

bool isBalenced(string exp)
{
    StackType<char> ch;

    for (int i = 0; i < exp.length(); i++)
    {
        char cdr = exp[i];

        if (cdr == '(')
        {
            ch.push(cdr);
        }
        else if (cdr == ')')
        {
            if (ch.isEmpty())
            {
                return false;
            }
            else
            {
                ch.pop();
            }
        }
    }

    return ch.isEmpty();
}
int main()
{

    string name = "Ta()((()))njim";
    cout << name[0] << endl;
    cout << name.length() << endl;

    if (isBalenced(name))
    {
        cout << "Balenced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}
