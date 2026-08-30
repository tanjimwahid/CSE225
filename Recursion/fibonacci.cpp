
#include <iostream>
#include <string>
using namespace std;
int printFibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return printFibo(n - 1) + printFibo(n - 2);
}
int main()
{
    cout << "print: 5 :" << printFibo(8) << endl;

    return 0;
}
