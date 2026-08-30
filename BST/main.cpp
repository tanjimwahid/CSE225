#include "bst.h"
#include "bst.cpp"
#include <iostream>
using namespace std;

int main()
{
    BST<int> tree;

    // Insert some values - mix of even and odd
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    tree.Insert(15);
    tree.Insert(25);

    cout << "In-order (all nodes): ";
    tree.Print();
    cout << endl;

    cout << "Even nodes only:      ";
    tree.PrintEvenNodes();
    cout << endl;

    cout << "Total node count: " << tree.Length() << endl;

    return 0;
}