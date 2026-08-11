// #include "stacktype.h"
#include "stacktype.cpp"
#include <iostream>
#include <string>
using namespace std;

template <class T>
void printStack(StackType<T> &s)
{
    T temp[SIZE];
    int n = 0;

    while (!s.isEmpty())
    {
        temp[n] = s.top();
        s.pop();
        n++;
    }

    for (int i = n - 1; i >= 0; i--)
        cout << temp[i] << " ";
    cout << endl;

    for (int i = n - 1; i >= 0; i--)
        s.push(temp[i]);
}

bool isBalanced(string &expr)
{
    StackType<char> s;

    for (char c : expr)
    {
        if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            if (s.isEmpty())
                return false;
            s.pop();
        }
    }

    return s.isEmpty();
}

int main()
{
    cout << "===== Task 1: Stack Operations =====" << endl
         << endl;

    StackType<int> stack;

    cout << "Check if the stack is empty: "
         << (stack.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;

    cout << "\nPushing 5, 7, 4, 2..." << endl;
    stack.push(5);
    stack.push(7);
    stack.push(4);
    stack.push(2);

    cout << "Check if the stack is empty: "
         << (stack.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;

    cout << "Check if the stack is full: "
         << (stack.isFull() ? "Stack is full" : "Stack is not full") << endl;

    cout << "Values in the stack: ";
    printStack(stack);

    cout << "\nPushing 3..." << endl;
    stack.push(3);
    stack.push(6);

    cout << "Values in the stack: ";
    printStack(stack);

    cout << "Check if the stack is full: "
         << (stack.isFull() ? "Stack is full" : "Stack is not full") << endl;

    cout << "\nPopping two items..." << endl;
    stack.pop();
    stack.pop();

    cout << "Top item: " << stack.top() << endl;

    cout << "\n===== Task 2: Balanced Parentheses =====" << endl
         << endl;

    string testCases[] = {
        "()",
        "(())()(()())()",
        "(())()((()",
        "(()))((()",
        "((()))))))"};

    for (int i = 0; i < 5; i++)
    {
        // cout << testCases[i];
        cout << testCases[i] << "  ->  " << (isBalanced(testCases[i]) ? "Balanced" : "Not Balanced") << endl;
    }
    // for (const string &test : testCases)
    // {
    //     cout << test << "  ->  ";
    //     //  << (isBalanced(test) ? "Balanced" : "Not Balanced") << endl;
    // }

    return 0;
}