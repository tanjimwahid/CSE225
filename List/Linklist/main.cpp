#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class MyList
{
private:
    Node *Head;
    Node *Tail;

public:
    MyList()
    {
        Head = NULL;
        Tail = NULL;
    }

    ~MyList()
    {
        if (Head != NULL)
        {
            delete Head;
            Head = NULL;
        }
    }
    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
        }
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = Head;
        int length = 0;
        for (int i = 0; i < pos - 1; i++)
        {

            if (temp == NULL)
            {
                cout << "Null Position: " << pos << " List Length " << length << endl;

                return;
            }
            temp = temp->next;
            length++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void getVal()
    {

        Node *temp = Head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    MyList ll;
    ll.pushFront(3);
    ll.pushFront(4);

    ll.pushFront(6);

    ll.pushFront(7);

    ll.pushBack(11);
    ll.pushBack(12);

    ll.insert(44, 2);

    ll.getVal();

    ll.insert(44, 27);
    ll.getVal();

    return 0;
}