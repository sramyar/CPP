#include"graph-matrix.cpp"
#include<cstdlib>
#include<iostream>
#include<fstream>

using namespace std;


double prob(void)
{
    return (1.0*rand()/RAND_MAX);
}

void generate_graph(Graph* const g, int size, double density)
{
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++){
            double p = prob();
            if(p<density && i != j){
                (*g).addEdge(i,j);
                (*g).c[i][j] = (rand()%3);
                (*g).w[i][j] = p*30;
            }
        }
    //return g;

}

void export_graph(string filename, Graph* const g)
{
    int size = g->n;
    ofstream outp(filename);
    outp << "Graph of size: " << size << '\n';
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++){
            if(g->v[i][j]){
                outp << i << '\t' << j << '\t' <<
                g->w[i][j] << '\t' << g->c[i][j] << '\n';
            }
        }
}

int main(void)
{
    int size;
    double density;
    cout << "Enter the graph size:" << endl;
    cin >> size;
    cout << "Now, enter the desired density in range (0,1):" <<endl;
    cin >> density;
    Graph g(size);
    generate_graph(&g,size,density);
    export_graph("graph.txt", &g);
    return 0;
}