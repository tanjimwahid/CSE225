#include <iostream>
using namespace std;

int main()
{
    int r = 2, c = 3; // 2 rows, 3 columns

    // Step 1: array of pointers (r pointers, each will point to a row)
    int **matrix = new int *[r];

    // Step 2: for each row, allocate c integers
    for (int i = 0; i < r; i++)
    {
        matrix[i] = new int[c];
    }

    // Fill it with values
    int val = 1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            matrix[i][j] = val++;

    // Print it
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    // Clean up - delete rows first, then the pointer array
    for (int i = 0; i < r; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}