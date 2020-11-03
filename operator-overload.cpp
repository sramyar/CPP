#include<iostream>
#include<ctime>
using namespace std;

typedef enum day{SUN,MON,TUE,WED,THU,FRI,SAT} day;

inline day next_day(day d)
{
    day next;
    return next = static_cast<day>(static_cast<int>(d)+1%7);
}

inline day operator++(day &d)
{
    return static_cast<day>(static_cast<int>(d)+1%7);
}

inline day operator+(day d1, day d2)
{
    return static_cast<day>(static_cast<int>(d1)+static_cast<int>(d2) + 1 % 7);
}

ostream& operator<<(ostream &out, const day &d)
{
    switch(d){
        case SUN: out << "SUN";break;
        case MON: out << "MON";break;
        case TUE: out << "TUE";break;
        case WED: out << "WED";break;
        case THU: out << "THU";break;
        case FRI: out << "FRI";break;
        default: out << "SAT";
    }
    return out;
}

int main(void)
{
    day d = SUN;
    day t = TUE;
    cout << "Today is: " << d << " next day is without cout overloading using nex_day() function: " << next_day(d) << endl;
    cout << "Today is: " << d << " next days is: " << ++d << endl;
    cout << "SUN+TUE is: " << d+t << endl;
    return 0;
}