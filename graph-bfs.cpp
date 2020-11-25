#include"graph-class.cpp"
#include<queue>



void bfs(Graph* const g, int init=0)
{
    vector<bool> added(g->n);
    queue<int> q;
    q.push(init);
    added[init] = true;
    while(!q.empty()){
        int curr = q.front();
        cout << "node: " << curr << " visited" << endl;
        vector<int> neighbors;
        g->outEdges(curr,neighbors);
        for(auto it:neighbors)
            if(added[it]==false){
                q.push(it);
                added[it]=true;
            }
        q.pop();
    }

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
    bfs(&g);
    return 0;
}