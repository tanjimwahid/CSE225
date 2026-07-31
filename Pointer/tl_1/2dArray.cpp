#include <iostream>
using namespace std;

int main()
{

    int r = 3, c = 3;
    int x = 0;
    int **matrix = new int *[r];
    for (int i = 0; i < 3; i++)
    {
        matrix[i] = new int[3];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = x;
            x++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}