#include"graph-class.cpp"
#include<map>

ostream& operator<<(ostream& out, map<int,double> m)
{
    for(auto i:m){
        out << i.first << ":\t" << i.second << endl;
    }

    return out;
}

void process_open(int indx, double curr, map<int,double>& open)
{
    //if indx not in open, add to open else update existing cost
    if(open.find(indx) == open.end() || curr < open.find(indx)->second)
        open[indx] = curr;

}


int get_min(map<int,double>* const open)
{
    int indx = open->begin()->first;
    double min = open->begin()->second;
    for(auto i:*open){
        if(i.second < min){
            min = i.second;
            indx = i.first;
        }
    }
    return indx;
    
}

bool hasVertex(vector<int>* const closed, int x)
{
    for (auto i:*closed){
        if(i==x) return true;
    }
    return false;
}

ostream& operator<< (ostream& out, vector<int>* const v)
{
    for(auto i:*v){
        out << i << '\t';
    }
    out << endl;
    return out;
}

ostream& operator<< (ostream& out, vector<pair<int,double>>* const v)
{
    for(auto i:*v){
        out << "(" << i.first << ", " << i.second << ")" << '\t';
    }
    out << endl;
    return out;
}

void jarnik_prim(Graph* const g, int init)
{
    vector<int> closed;
    closed.push_back(init);
    map<int,double> open;
    // inserting the adjacent vertices of init to the open set
    for (auto i:g->adj[init]){
        open[i.first] = i.second;
    }
    int min;
    while(closed.size() < g->n || open.size() > 0){
        //find smallest
        min = get_min(&open);
        
        // add chosen vertex to closed
        closed.push_back(min);
        for(auto iter:g->adj[min]){
            if(!hasVertex(&closed,iter.first)){
                process_open(iter.first, iter.second, open);
            }
        }

        open.erase(min);

    }

    cout << &closed;

}




int main(void)
{
    Graph g(7);
    g.addEdge(0,1,7);
    g.addEdge(1,0,7);
    g.addEdge(0,3,5);
    g.addEdge(3,0,5);
    g.addEdge(1,3,9);
    g.addEdge(3,1,9);
    g.addEdge(1,2,8);
    g.addEdge(2,1,8);
    g.addEdge(2,4,5);
    g.addEdge(4,2,5);
    g.addEdge(1,4,7);
    g.addEdge(4,1,7);
    g.addEdge(3,4,15);
    g.addEdge(4,3,15);
    g.addEdge(3,5,6);
    g.addEdge(5,3,6);
    g.addEdge(4,5,8);
    g.addEdge(5,4,8);
    g.addEdge(4,6,9);
    g.addEdge(6,4,9);
    g.addEdge(5,6,11);
    g.addEdge(6,5,11);
    jarnik_prim(&g,0);
    return 0;
}