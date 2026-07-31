#include <iostream>
#include <iomanip>
using namespace std;

class timeStamp
{
private:
    int seconds;
    int minutes;
    int hours;

public:
    timeStamp()
    {
        seconds = 0;
        minutes = 0;
        hours = 0;
    }

    timeStamp(int s, int m, int h)
    {
        seconds = s;
        minutes = m;
        hours = h;
    }

    // total seconds since midnight — makes comparison trivial
    int Total()
    {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void Print()
    {
        cout << setfill('0') << setw(2) << seconds << ": "
             << setw(2) << minutes << ": "
             << setw(2) << hours << endl;
    }

    bool operator<(timeStamp &other)
    {
        return Total() < other.Total();
    }
    bool operator>(timeStamp &other)
    {
        return Total() > other.Total();
    }
    bool operator==(timeStamp &other)
    {
        return Total() == other.Total();
    }
};