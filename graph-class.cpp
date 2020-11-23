#include<iostream>
#include<vector>
using namespace std;


class Graph{
    
    public:
    int n;
    vector<vector<pair<int,double>>> adj;

    Graph(int num)
    {
        this->n = num;
        adj = vector<vector<pair<int,double>>>(num);
    }

    void addEdge(int i, int j, double w = 0)
    {
        adj[i].push_back(make_pair(j,w));
    }

    void removeEdge(int i, int j)
    {
        for(int k=0; k< adj[i].size(); k++){
            if (adj[i][k].first == j){
                adj[i].erase(adj[i].begin() + k);
            };
        }

    }

    bool hasEdge(int i, int j)
    {
        for(int k=0; k<adj[i].size(); k++){
            if(adj[i][k].first == j) return true;
        }

        return false;
    }

    void outEdges(int i, vector<pair<int,double>>& edges)
    {
        for(auto iter: adj[i]){
            edges.push_back(iter);
        }
    }

    void inEdges(int i, vector<pair<int,double>>& edges)
    {
        for(auto iter: adj){
            for(auto iter2: iter){
                if(iter2.first == i) edges.push_back(iter2);
            }
        }
    }

    friend ostream& operator <<(ostream& out, Graph g)
    {
        for(int i=0; i< g.n; i++)
            for(auto j:g.adj[i]){
                out << i << ":\t(" << j.first << ", " << j.second << ")" << endl;
            }
        return out;
    }
};

int main(void)
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    cout << g;
    return 0;
}