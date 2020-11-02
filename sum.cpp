// Converting C to C++ program

#include<iostream>
using namespace :: std;

void sum(int* p, int size, int d[])
{
    *p = 0;
    for (int i=0; i<size; i++)
        *p+=i;
}

int main(void)
{
    const int n = 40;
    int accum;
    int d[n];
    for(int i=0; i<n; i++)
        d[i] = i;
    sum(&accum, n, d);
    cout << "The sum is: " << accum << endl;
    return 0;
}