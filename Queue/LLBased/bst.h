#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include "queue.h"
template <class T>
struct Node
{
    T data;
    Node *left;
    Node *right;
};
enum OrderType
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

/*
PRE_ORDER = 0

IN_ORDER = 1

POST_ORDER = 2
*/
template <class T>
class BST
{
private:
    Node<T> *root;
    Queue<T> preQue;
    Queue<T> inQue;
    Queue<T> postQue;
    void BuildBST(T arr[], int start, int end);

public:
    BST();
    ~BST();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    int Length();
    void Insert(T value);
    void Search(T &value, bool &found);
    void Delete(T value);
    void GetNext(T &value, OrderType order);
    void Reset(OrderType order);
    void Print();
    void BuildOptimalTree();
};
#endif // BST_H_INCLUDED