#ifndef STACKTYPE_H
#define STACKTYPE_H

const int SIZE = 5;
class FullStack
{
};
class EmptyStack
{
};
template <class T>
class StackType
{
private:
    T *;
    int topIndex;

public:
    StackType();
    ~StackType();
    bool isFull();
    bool isEmpty();
    void makeEmpty();
    void push(T);
    void pop();
    T top();
};

#endif