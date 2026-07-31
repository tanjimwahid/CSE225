#include "sortedType.h"
#include "timeStamp.cpp"
#include <iostream>
using namespace std;
int main()
{
    SortedType<timeStamp> list;

    list.Insert(timeStamp(15, 34, 23));
    list.Insert(timeStamp(13, 13, 02));
    list.Insert(timeStamp(43, 45, 12));
    list.Insert(timeStamp(25, 36, 17));
    list.Insert(timeStamp(52, 02, 20));

    list.Delete(timeStamp(25, 36, 17));

    timeStamp temp;
    list.Reset();
    for (int i = 0; i < list.Length(); i++)
    {
        list.GetNext(temp);
        temp.Print();
    }

    return 0;
}