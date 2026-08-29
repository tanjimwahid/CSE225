#ifndef QUEUE_H
#define QUEUE_H

class EmptyQueue
{
};
class FullQueue
{
};
template <class T>

class Queue
{
public:
    struct NodeType
    {
        T data;
        NodeType *next;
    };
    Queue();
    ~Queue();
    void enQueue(T);
    void makeEmpty();
    void deQueue(T &data);
    T frontValue();
    bool isEmpty();

private:
    NodeType *front;
    NodeType *rear;
};

#endif