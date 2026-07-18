#include <iostream>
using namespace std;

int main()
{

    int **arr = new int *[2];
    int i, j;
    for (i = 0; i < 2; i++)
        arr[i] = new int[2];
    cout << "Please Enter The Value: " << endl;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            int value;
            cin >> value;
            arr[i][j] = value;
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < 2; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}