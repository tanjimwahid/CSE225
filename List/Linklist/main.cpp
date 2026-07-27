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
        Node *temp;

        while (Head != NULL)
        {
            temp = Head;
            Head = Head->next;
            delete temp;
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

    void popFront()
    {
        if (Head == NULL)
        {
            cout << " EMPTY ERROR " << endl;
            return;
        }

        Node *temp = Head;
        Head = Head->next;
        temp->next = NULL;
        delete temp;

        if (Head == NULL) // we just popped the last node
            Tail = NULL;
    }

    void popBack()
    {
        if (Head == NULL)
        {
            cout << "Error: Null Head " << endl;
            return;
        }

        if (Head == Tail) // only one node
        {
            delete Head;
            Head = Tail = NULL;
            return;
        }

        Node *temp = Head;
        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        temp->next = NULL;
        Tail = temp;
    }

    void IRSearch(int &value, int key)
    {
        Node *temp = Head;
        int length = 0;
        while (temp != NULL)
        {
            if (length == key - 1)
            {
                cout << "Value at : " << key << " : " << temp->data << endl;
                value = temp->data;
                return;
            }
            temp = temp->next;
            length++;
        }
        cout << "Error: Key is higher than length" << endl;
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
    ll.pushFront(4);
    ll.pushFront(3);

    ll.pushFront(2);

    ll.pushFront(1);
    ll.pushBack(5);

    // ll.pushBack(11);
    // ll.pushBack(12);

    // ll.insert(44, 2);
    ll.getVal();
    // ll.popFront();
    // ll.popBack();

    int value;

    ll.IRSearch(value, 1);
    ll.IRSearch(value, 2);
    ll.IRSearch(value, 5);
    ll.IRSearch(value, 30);

    // ll.insert(44, 27);
    ll.getVal();

    return 0;
}