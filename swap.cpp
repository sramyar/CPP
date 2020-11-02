#include<iostream>
using namespace :: std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int i = 1, j = 3;
    double a = 12.5, b = 5.11;
    cout << "The two integers before swap are: " << i << " and " << j << endl;
    swap(i,j);
    cout << "The two integers after swapping: " << i << " and " << j << endl;
    cout << "The doubles before swapping: " << a << " and " << b << endl;
    swap(a,b);
    cout << "The doubles after swapping: " << a << " and " << b << endl;
    
    return 0;
}