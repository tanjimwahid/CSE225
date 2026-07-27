#include "unSortedType.cpp"
#include <iostream>
using namespace std;

void printList(UnsortedType<int> &list)
{
    int value;

    for (int i = 0; i < list.Length(); i++)
    {
        list.GetNext(value);
        cout << value << " ";
    }

    cout << endl;
}

int main()
{
    UnsortedType<int> list1, list2, mergeList;

    // task 01
    /*
    tt.Insert(5);
    tt.Insert(7);
    tt.Insert(6);
    tt.Insert(9);

    printList(tt);
    tt.Insert(1);
    printList(tt);
    tt.Delete(5);

    printList(tt);
    tt.Delete(16);
    printList(tt);
    */
}