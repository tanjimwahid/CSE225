#ifndef UNSORTEDTYPE_H_INCLUDED
#define UNSORTEDTYPE_H_INCLUDED

const int MAX_ITEMS = 100;

template <class ItemType>
class UnsortedType
{
public:
    UnsortedType();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void InsertItem(ItemType);
    void DeleteItem(ItemType);
    void RetrieveItem(ItemType&, bool&);
    void ResetList();
    void GetNextItem(ItemType&);

private:
    int length;
    ItemType info[MAX_ITEMS];   // writing head
    int currentPos;             // reading head
};

//---------------------------------------------------------
// Constructor
//---------------------------------------------------------
template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    currentPos = -1;
}

//---------------------------------------------------------
// MakeEmpty
// Resets length to 0 -- doesn't physically clear the array,
// just marks all slots as unused/overwritable.
//---------------------------------------------------------
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    length = 0;
}

//---------------------------------------------------------
// IsFull
//---------------------------------------------------------
template <class ItemType>
bool UnsortedType<ItemType>::IsFull()
{
    return (length == MAX_ITEMS);
}

//---------------------------------------------------------
// LengthIs
//---------------------------------------------------------
template <class ItemType>
int UnsortedType<ItemType>::LengthIs()
{
    return length;
}

//---------------------------------------------------------
// ResetList
//---------------------------------------------------------
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
    currentPos = -1;
}

//---------------------------------------------------------
// GetNextItem
//---------------------------------------------------------
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
{
    currentPos++;
    item = info[currentPos];
}

//===========================================================
// NOTE: The three methods below (InsertItem, DeleteItem,
// RetrieveItem) were NOT visible in the slide images you sent.
// These are the standard array-based unsorted-list versions
// (Malik-style) -- check them against your actual slide before
// relying on them for an assignment/exam.
//===========================================================

//---------------------------------------------------------
// InsertItem
// Unsorted list -> always insert at the end, O(1)
//---------------------------------------------------------
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
{
    info[length] = item;
    length++;
}

//---------------------------------------------------------
// DeleteItem
// Find the item, then move the last element into its spot
// (order doesn't matter in an unsorted list) -> O(n)
//---------------------------------------------------------
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
{
    int location = 0;
    while (!(item == info[location]))
        location++;

    info[location] = info[length - 1];
    length--;
}

//---------------------------------------------------------
// RetrieveItem
// Linear search; sets found = true/false and, if found,
// fills 'item' with the matching element's full data.
//---------------------------------------------------------
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    int location = 0;
    found = false;

    while (!found && location < length)
    {
        if (item == info[location])
            found = true;
        else
            location++;
    }

    if (found)
        item = info[location];
}

#endif // UNSORTEDTYPE_H_INCLUDED