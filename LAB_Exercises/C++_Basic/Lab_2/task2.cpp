#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cout << "Enter Num of Row and Cols" << endl;
    cin >> r >> c;
    char **ptr = new char *[r];
    for (int i = 0; i < r; i++)
    {
        ptr[i] = new char[c];
    }

    for (int i = 0; i < r; i++)
    {
        string name;
        cin >> name;
        for (int j = 0; j < c; j++)
        {
            ptr[i][j] = name[j];
        }
    }

    cout << " You have entered" << endl;

    for (int i = 0; i < r; i++)
    {
        cout << "{";
        for (int j = 0; j < c; j++)
        {
            cout << ptr[i][j];
            if (j < c - 1)
                cout << " ,";
        }
        cout << "}";
        cout << endl;
    }
}