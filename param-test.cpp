#include<iostream>
#include<vector>
using namespace std;

template<class T>
void square(vector<T>* const v)
{
    auto i = v->begin();
    for(;i!=v->end();i++){
        *i = (*i)*(*i);
    }
}


int main(void)
{
    vector<int> v(5,2);
    square(&v);
    for(auto i:v){
        cout << i << '\t';
    }
    cout << endl;
    return 0;
}