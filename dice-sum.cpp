#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace :: std;

const int sides = 6;
inline int roll_dice(){return (rand()%sides + 1);}

int main()
{
    int result[13] = {0};
    int trials;
    int d1, d2;
    srand(clock());
    cout << "Enter the number of trials:"<<endl;
    cin >> trials;
    for(int i=0; i < trials; i++){
        result[(d1 = roll_dice())+(d2 = roll_dice())]++;
    }

    double r;

    for(int i=2; i <=12; i++){
        cout << "The probability of sum = "<<i<<" is: "<<((double)result[i]/trials)<<endl;
    }

    return 0;
}