#include "bst.h"
#include "bst.cpp"
#include <iostream>
using namespace std;

// Helper function to print a tree in a given traversal order using GetNext/Reset
template <class T>
void printTraversal(BST<T> &tree, OrderType order)
{
    tree.Reset(order);
    T value;
    int n = tree.Length();
    for (int i = 0; i < n; i++)
    {
        tree.GetNext(value, order);
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    // ---------------------------------------------------------
    // Base Tasks: Insert, Print (inorder/preorder/postorder),
    // Search, Delete
    // ---------------------------------------------------------
    cout << "===== Base BST Tasks =====" << endl;

    BST<int> tree;

    // Insert seven items
    int items[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < 7; i++)
        tree.Insert(items[i]);

    // Print inorder
    cout << "Inorder: ";
    printTraversal(tree, IN_ORDER);

    // Print preorder
    cout << "Preorder: ";
    printTraversal(tree, PRE_ORDER);

    // Print postorder
    cout << "Postorder: ";
    printTraversal(tree, POST_ORDER);

    // Search 20
    int searchVal = 20;
    bool found = false;
    tree.Search(searchVal, found);
    cout << "Search 20: " << (found ? "Found" : "Not Found") << endl;

    // Search 15
    searchVal = 15;
    found = false;
    tree.Search(searchVal, found);
    cout << "Search 15: " << (found ? "Found" : "Not Found") << endl;

    // Delete 20
    tree.Delete(20);
    cout << "After deleting 20:" << endl;

    // Print inorder
    cout << "Inorder: ";
    printTraversal(tree, IN_ORDER);

    // Print preorder
    cout << "Preorder: ";
    printTraversal(tree, PRE_ORDER);

    // Print postorder
    cout << "Postorder: ";
    printTraversal(tree, POST_ORDER);

    cout << endl;

    // ---------------------------------------------------------
    // Task 1: Optimal (minimum height) BST construction
    // ---------------------------------------------------------
    cout << "===== Task 1: Optimal BST =====" << endl;

    BST<int> tree2;
    int seq[] = {11, 9, 4, 2, 7, 3, 17, 0, 5, 1};
    int n = sizeof(seq) / sizeof(seq[0]);

    for (int i = 0; i < n; i++)
        tree2.Insert(seq[i]);

    cout << "Without Optimal Ordering:" << endl;
    cout << "Inorder: ";
    printTraversal(tree2, IN_ORDER);
    cout << "Preorder: ";
    printTraversal(tree2, PRE_ORDER);
    cout << "Postorder: ";
    printTraversal(tree2, POST_ORDER);

    // Rebuild as a balanced (minimum height) BST
    tree2.BuildOptimalTree();

    cout << endl
         << "With Optimal Ordering:" << endl;
    cout << "Inorder: ";
    printTraversal(tree2, IN_ORDER);
    cout << "Preorder: ";
    printTraversal(tree2, PRE_ORDER);
    cout << "Postorder: ";
    printTraversal(tree2, POST_ORDER);

    return 0;
}