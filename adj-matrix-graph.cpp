#include<iostream>

using namespace std;

int n;
bool **a;

void addEdge(int i, int j)
{
    a[i][j] = true;
}

void removeEdge(int i, int j)
{
    a[i][j] = false;
}

bool hasEdge(int i, int j)
{
    return a[i][j];
}

int outEdges(int i, List &edges)
{
    int out = 0;
    for (int j=0; j<n; j++){
        if(a[i][j]) out++;
    }
    return out;
}

int main(void)
{
    int n;
    bool a[n][n];
    return 0;
}