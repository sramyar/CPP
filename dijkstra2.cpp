#include"graph-matrix.cpp"
#include<map>

int find_min(map<int,double>* open)
{
    double min = open->begin()->second;
    int min_indx=open->begin()->first;
    for(auto it: *open){
        if(it.second < min){
            min = it.second;
            min_indx = it.first;
        }
    }
    return min_indx;
}

void print_map(map<int,double>m)
{
    for(auto x:m){
        cout << x.first << ' ' << x.second << '\t';
    }
    cout << endl;
}

void printv(vector<int> v)
{
    for(auto i:v){
        cout << i << '\t';
    }
    cout << endl;
}


void process_open(int v, vector<int>* const out, double curr,
        map<int,double>* const closed, map<int,double>* const open, Graph* const g)
{
    //get vertices connected to v
    g->outEdges(v,*out);
    //add vertex to open set if not already in it OR update the cost
    for(int it:*out){
        if(closed->find(it) == closed->end()){
            if(open->find(it) == open->end()) (*open)[it] = curr+g->c[v][it];
            else{
                if(open->at(it) > curr+g->c[v][it]) (*open)[it] = curr+g->c[v][it];
            }
        }
    }
}

void dijsktra(int start, int end, Graph* const g)
{
    map<int,double> closed;
    map<int,double> open;
    vector<int> out;
    double curr = 0;
    closed[start] = 0;
    process_open(start,&out,curr,&closed,&open,g);
    while(open.size()>0 && closed.find(end)==closed.end()){
        out.clear();
        //fetch the next vertex with min distance
        int v = find_min(&open);
        //update current distance based on chosen next vertex
        curr = open[v];
        closed[v]=curr; 
        //process open set
        process_open(v,&out,curr,&closed,&open,g);
        //remove v from open set
        open.erase(v);
        print_map(open);
    }

}


int main(void)
{
    Graph G(9);
    G.addEdge(0,1,4);
    G.addEdge(0,4,7);
    G.addEdge(0,3,3);
    G.addEdge(3,0,3);
    G.addEdge(1,2,1);
    G.addEdge(2,4,3);
    G.addEdge(3,4,4);
    G.addEdge(2,5,1);
    G.addEdge(4,5,1);
    G.addEdge(4,6,5);
    G.addEdge(4,8,3);
    G.addEdge(5,7,2);
    G.addEdge(7,5,2);
    G.addEdge(5,8,4);
    G.addEdge(7,8,3);
    G.addEdge(8,6,5);
    dijsktra(0,8,&G);
    return 0;
}