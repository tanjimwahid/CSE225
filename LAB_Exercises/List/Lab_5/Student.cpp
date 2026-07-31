#include "unSortedType.cpp"
#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    double cg;
    int id;

public:
    Student();
    Student operator==(Student);
};