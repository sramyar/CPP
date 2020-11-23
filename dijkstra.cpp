#include<iostream>
#include"graph.cpp"
using namespace std;







Node<int>* findMin(List<int>* open, List<double>* weights)
{
    //cout << "troble" << endl;
    int minIndex = weights->minElementIndex();
    return open->getElement(minIndex);
}

double getWeight(Node<int>* const x, List<int>*  nodes, List<double>* w)
{
    // find weight associated with vertex cue using index
    int index = nodes->getIndex(x->data);
    double weight = (w->getElement(index))->data;
    return weight;
}

void processVertex(Graph* const G, Node<int>* const x, List<int>* closed, List<int>* open, List<double>* weights)
{   
    List<int>* outedges = &(G->V.at(x->data));
    //outedges->print();
    List<double>* outweights = &(G->W.at(x->data));
    double wx = getWeight(x, open, weights);
    if(outedges->isEmpty()){
        closed->add(x->data);
        int idx = open->getIndex(x->data);
        open->remove(idx);
        weights->remove(idx);
        return;
    }
    Node<int>* cue = outedges->head;
    while(cue != nullptr){
        double w = getWeight(cue, outedges, outweights);

        // if outgoing vertex from cue not in open, add to open
        if (!(open->hasElement(cue->data)) && !(closed->hasElement(cue->data))){
            int val = cue->data;
            (*open).add(val);
            //open->print();
            (*weights).add(w+wx);
        }

        // if outgoing vertex from cue already in open, update the corresponding value in weights list
        // if a shorter path, update the corresponding weight to indicate the shorter path
        if ((open->hasElement(cue->data)) && !(closed->hasElement(cue->data)))
        {
            int idx = open->getIndex(cue->data);
            if (w+wx < weights->getElement(idx)->data) (*weights).getElement(idx)->data = w+wx;
            //cout << "updated" << endl;

        }
        
        cue = cue->nxtPtr;
        
    }
    // adding x to closed and removing from open
    (*closed).add(x->data);
    //cout << "visited" << endl;
    int idx = open->getIndex(x->data);
    (*open).remove(idx);
    (*weights).remove(idx);
    //cout << "removed from open" << endl;
}

void dijkstra(Graph* const G, int start, int end)
{
    List<int> closed;
    closed.add(start);
    List<int>* v = &(G->V.at(start));
    List<double>* w = &(G->W.at(start));
    List<int> open(v,true);
    List<double> weights(w,true);
    Node<int>* node;
    while (!(closed.hasElement(end)) || !open.isEmpty()){
        node = findMin(&open, &weights);
        weights.print();
        cout << "vertex: " << node->data << " is min" << endl;
        processVertex(G, node, &closed, &open, &weights);
        //cout << "Vertex: " << node->data << "\tcost: " << getWeight(node, &open, &weights) << endl;
    }

}

/*
Node<int>* findMin(Graph* const G, Node<int>* const from, List<int>* const open)
{
    Node<int>* Min;
    Node<int>* cue = open->head;
    List<int>* dests;
    List<double>* weights;
    // knowing weights are strictly less than 1000
    double curr, min = 1000;
    int i = from->data;
    int j;
    // 'dests' is nodes reachable from i or start point/from Node
    dests = &G->V.at(i);
    while(cue != nullptr){
        if(dests->hasElement(cue->data)){
            // if current Node in open set/cue is in destinations reachable from i, find corresponding index j
            j = dests->getIndex(cue->data);
            weights = &G->W.at(i);
            // get the weight from i to j based on corresponding index j
                //curr = weights->getElement(1000);
            // updating the min
            if (curr < min){
                min = curr;
                Min = cue;
            }
        }
        // advancing the cue
        cue = cue->nxtPtr;
    }
    return nullptr;


}
*/

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
    dijkstra(&G,0,8);
    return 0;
}
