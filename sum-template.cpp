#include<iostream>
using namespace std;

template<class T>
T sum(int size, const T a[])
{
    T s = 0;
    for (int i=0; i<size; i++)
        s += a[i];
    return s;
}

template<class T>
void print_array(int size, const T a[])
{
    for (int i=0; i<size; i++)
        cout << i <<"'th element is: " << a[i] << endl;
    cout << endl;
}

int main(void)
{
    int a[] = {10,20,30};
    int s = sum(3,a);
    print_array(3,a);
    cout << "The sum of "<< a << " containing integers is " << s << endl;
    double ad[] = {10.0, 20.0, 30.0};
    print_array(3,ad);
    double sd = sum(3,ad);
    cout << "The sum of " << ad << " containing doubles is " << sd << endl;
    return 0;
}