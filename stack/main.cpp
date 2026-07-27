#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

// Exception class thrown by Push when the stack is full
class FullStack
{
};

// Exception class thrown by Pop and Top when the stack is empty
class EmptyStack
{
};

template <class T>
class StackType
{
private:
    T *data;
    int top;

public:
    StackType();
    ~StackType();
    bool IsFull();
    bool IsEmpty();
    void Push(T);
    void Pop();
    T Top();
};

template <class T>
StackType<T>::StackType()
{
    data = new T[SIZE];
    top = -1;
}

template <class T>
StackType<T>::~StackType()
{
    delete[] data;
}

template <class T>
bool StackType<T>::IsEmpty()
{
    return (top == -1);
}

template <class T>
bool StackType<T>::IsFull()
{
    return (top == SIZE - 1);
}

template <class T>
void StackType<T>::Push(T value)
{
    try
    {
        if (IsFull())
            throw FullStack();
        else
        {
            top++;
            data[top] = value;
        }
    }
    catch (FullStack e)
    {
        cout << "Error: Stack is full" << endl;
    }
}

template <class T>
void StackType<T>::Pop()
{
    try
    {
        if (IsEmpty())
            throw EmptyStack();
        else
            top--;
    }
    catch (EmptyStack e)
    {
        cout << "Error: Stack is empty" << endl;
    }
}

template <class T>
T StackType<T>::Top()
{
    try
    {
        if (IsEmpty())
            throw EmptyStack();
        else
            return data[top];
    }
    catch (EmptyStack e)
    {
        cout << "Error: Stack is empty" << endl;
    }
}

void PrintStack(StackType<int> &s)
{
    StackType<int> temp;

    while (!s.IsEmpty())
    {
        temp.Push(s.Top());
        s.Pop();
    }

    bool first = true;
    while (!temp.IsEmpty())
    {
        int value = temp.Top();
        temp.Pop();

        if (!first)
            cout << ", ";
        cout << value;
        first = false;

        s.Push(value);
    }
    cout << endl;
}

int main()
{
    StackType<int> stack;

    if (stack.IsEmpty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;

    stack.Push(5);
    stack.Push(7);
    stack.Push(4);
    stack.Push(2);

    if (stack.IsEmpty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;

    if (stack.IsFull())
        cout << "Stack is full" << endl;
    else
        cout << "Stack is not full" << endl;

    PrintStack(stack);

    stack.Push(3);

    PrintStack(stack);

    if (stack.IsFull())
        cout << "Stack is full" << endl;
    else
        cout << "Stack is not full" << endl;

    stack.Pop();
    stack.Pop();

    cout << stack.Top() << endl;

    return 0;
}