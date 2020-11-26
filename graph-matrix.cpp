#include<vector>
#include<iostream>
using namespace std;


class Graph{
    public:

    int n;
    bool** v;    //vertices
    double** w;  //weights (or costs)
    int** c;     //colors

    Graph(int num){
        this->n = num;
        v = new bool*[num];
        w = new double*[num];
        c = new int*[num];
        for(int i=0; i<num; i++){
            v[i] = new bool[num];
            c[i] = new int[num];
            w[i] = new double[num];
        }
    }
    //destructor
    ~Graph(){
        cout << "graph destructor called" << endl;
    }

    void addEdge(int i, int j)
    {
        this->v[i][j] = true;
    }

    void removeEdge(int i, int j)
    {
        this->v[i][j] = false;
    }

    bool hasEdge(int i, int j)
    {
        return this->v[i][j];
    }

    void outEdges(int i, vector<int>& edges)
    {
        for(int j=0;j<this->n;j++){
            if(v[i][j]) edges.push_back(j);
        }
    }

    void inEdges(int i, vector<int>& edges)
    {
        for(int j=0; j<this->n; j++){
            if(v[j][i]) edges.push_back(j);
        }
    }



};
