
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

int sum(int num)
{

    if (num == 0)
        return 0;
    return num + sum(num - 1);
}
int main()
{
    cout << "Sum of 4: " << sum(4) << endl;
}
