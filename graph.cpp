#include<iostream>
#include<vector>
#include"linked-list.cpp"
using namespace std;

class Graph{
    public:
    int n;
    vector<List<int>> V;
    vector<List<double>> W;

    Graph(int nodes)
    {
        for(int i=0; i< nodes; i++){
            V.push_back(*new List<int>());
            W.push_back(*new List<double>());
        }

    }

    void addEdge(int i, int j, double w=0)
    {
        if(!hasEdge(i,j)) {
            V[i].add(j);
            W[i].add(w);
        }
        else return;
    }

    bool hasEdge(int i, int j)
    {
        return V[i].hasElement(j);
    }

    void removeEdge(int i, int j)
    {
        if(hasEdge(i,j)) V[i].remove(j);
        else return;
    }

    List<int>* outEdges(int i)
    {
        return &V[i];
    }

    List<int> inEdges(int j)
    {
        List<int>out;
        for(int i=0; i<n; i++){
            if(this->hasEdge(i,j)) out.add(i);
        }

        return out;
    }

    void print(void)
    {
        
        for(int i=0; i < this->V.size(); i++){
            Node<int>* cue = this->V[i].head;
            cout << "Node " << i << ":" << '\t';
            while(cue != nullptr){
                cout << cue->data << '\t';
                cue = cue->nxtPtr;
            }
            cout << '\n';
        }
    return ;
    }
    
};


ostream& operator<<(ostream& out, Graph const &G)
{
    for(int i=0; i < G.V.size(); i++){
        Node<int>* cue = G.V[i].head;
        while(cue != nullptr){
            out << cue->data << '\t';
            cue = cue->nxtPtr;
        }
        out << '\n';
    }
    return out;
}


/*
int main(void)
{

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(2,1);
    g.print();
    g.removeEdge(2,3);
    g.print();
    g.addEdge(1,2);
    //g.print();
    return 0;   
}

*/