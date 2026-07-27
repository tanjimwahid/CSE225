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
void insertArr(int size, int arr[], UnsortedType<int> &list)
{
    for (int i = 0; i < size; i++)
    {
        list.Insert(arr[i]);
    }
}

void merge2List(UnsortedType<int> &list1, UnsortedType<int> &list2, UnsortedType<int> &mergeVal)
{
    int list2Size = list2.Length();
    int list1Size = list1.Length();
    int i = 0, value, x = 0;
    for (int i = 0; i < list1Size; i++)
    {
        list1.GetNext(value);
        mergeVal.Insert(value);
    }
    for (int i = 0; i < list2Size; i++)
    {
        list2.GetNext(value);
        mergeVal.Insert(value);
    }

    list1.MakeEmpty();
    list2.MakeEmpty();
}

// void sortList(UnsortedType<int> &list1, UnsortedType<int> &list2)
// {

//     int val, val2;
//     int temp;
//     for (int i = 0; i < list1.Length(); i++)
//     {
//         list1.GetNext(val);

//         for (int j = 0; j < list1.Length(); j++)
//         {
//             list1.GetNext(val2);

//             if (val > val2)
//             {
//                 temp = val;
//                 val = val2;
//                 val2 = temp;
//             }
//         }
//         list2.Insert(val);
//         list1.Reset();
//     }
// }

void sortList(UnsortedType<int> &list1, UnsortedType<int> &list2)
{
    int length = list1.Length();
    int value, minVal, maxVal;
    list1.Reset();
    list1.GetNext(value);
    minVal = maxVal = value;
    for (int i = 1; i < length; i++)
    {
        list1.GetNext(value);
        if (value < minVal)
            minVal = value;
        if (value > maxVal)
            maxVal = value;
    }
    list1.Reset();

    bool found;
    for (int v = maxVal; v >= minVal; v--)
    {
        list1.Search(v, found);
        if (found)
            list2.Insert(v);
    }
}
int main()
{
    UnsortedType<int> list1, list2, mergeList, sortListt;

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

    // 10 1 5 6 10 14 20 25 31 38 40
    int arr1[11] = {10, 1, 5, 6, 10, 14, 20, 25, 31, 38, 40};
    int arr2[13] = {12, 2, 4, 7, 9, 16, 19, 23, 24, 32, 35, 36, 42};
    insertArr(11, arr1, list1);
    insertArr(13, arr2, list2);
    printList(list1);
    printList(list2);

    merge2List(list1, list2, mergeList);
    printList(mergeList);
    sortList(mergeList, sortListt);
    printList(sortListt);
}