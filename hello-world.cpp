#include<iostream>
using namespace :: std;

long long fact_iter(int n)
{
    long long f = 1;
    for(int i=1; i<=n; i++)
        f *= i;
    return f;
}

long long fact_recu(int n)
{
    long long f = 1;
    if(n == 0) return f;
    return n*fact_recu(n-1);
}


int main(void)
{
    int n;
    cout << "Hello World!";
    cout << "Enter a number: " << endl;
    cin >> n;
    long long f1 = fact_recu(n);
    long long f2 = fact_iter(n);
    cout <<"Factorial of "<< n <<" is "<<f1<<" when computed recursively"<<endl<<"and "<<f2<<" when computed iteratively"<<endl;
    return 0;
}