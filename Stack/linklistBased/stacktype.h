#ifndef STACKTYPE_H
#define STACKTYPE_H
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
    struct Node
    {
        T data;
        Node *next;
    };

private:
    Node *head;

public:
    StackType();
    ~StackType();
    bool IsEmpty();
    bool IsFull();
    void Push(T);
    void Pop();
    T Top();
};
#endif