#ifndef CHARRAY_H
#define CHARRAY_H

class chArray
{
private:
    char *arr;
    int size = 0;
    int index = 0;

public:
    chArray();
    chArray(char c, int size);
    void outputstr();
    void inputStr(char c);
};

#endif
