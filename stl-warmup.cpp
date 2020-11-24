#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iterator>

using namespace std;

void get_char_print_them(void)
{
    int n;
    cout << "insert the number of values:" << endl;
    cin >> n;
    vector<char> v(n);
    cout << "insert values:" << endl;
    //for(vector<char>::iterator x = v.begin(); x!=v.end();x++)
    //    cin >> *x;
    for(auto &x:v)
        cin >> x;
    cout << "the container thus is;" << endl;
    for(auto c:v)
        cout << c << '\t';
    cout << endl;
}

void average_from_file(void)
{
    cout << "enter the file name (with extension):" << endl;
    string fname;
    cin >> fname;
    ifstream data_file(fname);
    istream_iterator<char> start(data_file), end;
    vector<char> data(start,end);
    cout << "vectorizing and re-printing:" << endl;
    for (char c:data)
        cout << c;    
    cout << endl;
    cout << static_cast<int>(' ') << endl;
    for(auto c:"why not?")
        cout << c;
    cout << endl;
}

int main(void)
{
    //get_char_print_them();
    average_from_file();
    return 0;
}