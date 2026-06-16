#include <iostream>
using namespace std;

int main()
{

    int a, b;
    cout << "Input 2 Numbers ";
    cin >> a >> b;
    int fact = 1;
    char sign;
    cout << "Select operation ";
    cin >> sign;
    int result;
    switch (sign)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (a > b)
        {
            result = a / b;
        }
        else
        {
            result = b / a;
        }
        break;
    default:
        break;
    }

    cout << "Result " << result;
    return 0;
}