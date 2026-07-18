#include <iostream>
using namespace std;

int main()
{
    int *grades;
    int num;
    int total;
    cout << "Enter The Number" << endl;

    cin >> num;
    grades = new int[num];
    cout << grades << endl;
    cout << *grades << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> grades[i];
    }
    for (int i = 0; i < num; i++)
    {
        total += grades[i];
    }
    cout << "Avg: " << (int)total / num << endl;
    delete[] grades;
    grades = NULL;
    cout << grades << endl; // Still hold the memory locaiton
    cout << *grades << endl;
    return 0;
}