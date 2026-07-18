#include <iostream>
#include "chArray.h"
using namespace std;

int main()
{
    chArray a;
    a.inputStr('H');
    a.inputStr('i');
    a.outputstr();

    chArray b('X', 5);
    b.outputstr();

    return 0;
}
