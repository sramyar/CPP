#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;


double sample()
{
    int d = rand()%4;
    if(d < 2) return 1.0;
    else if (d == 2) return 2.0;
    else return 3.0;

}

long double product(int n)
{
    long double prod = 1;
    long double s;
    for(int i=0; i < n; i++)
        {s = sample();
        prod = prod*s;
        }
    return prod;
}


int main(void)
{
    int n;
    srand(clock());
    const double reference = pow(6,0.25);
    cout << "Enter the number of trials: " << endl;
    cin >> n;
    long double x =  1/(static_cast<long double>(n));
    long double p = product(n);
    long double r = pow(p,x);
    cout << "The expression for n= " << n << " is: " << r << " and analytic solution is: " << reference << endl;
    return 0;
}