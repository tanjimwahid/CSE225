#ifndef DYNARR_H
#define DYNARR_H

template <class T>
class dynArr
{
private:
    T *data;
    int size;

public:
    dynArr();
    dynArr(int s);
    ~dynArr();
    void setValue(int index, int value);
    T getValue(int index);
    void allocate(int s);
};
#endif // DYNARR_H