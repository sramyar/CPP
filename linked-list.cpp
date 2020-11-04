#include<iostream>

using namespace std;

template<class T>
class Node{

    public:
    
    Node* nxtPtr;
    T data;

    
    Node():nxtPtr(NULL),data(0){}

    Node(T d)
    {
        this -> data = d;
        this -> nxtPtr = NULL;
    }
};

template<class T>
class List{

    public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    List():head(0),tail(0),size(0){};

    T push(T x)
    {
        Node<T>* u = new Node<T>(x);
        u->nxtPtr = head;
        head = u;

        if (size==0){
            tail = u;
            size++;
        }
        else size++;

        return x;
    }

    T pop(void)
    {
        if(size == 0) return NULL;
        T val = this->head->data;
        this->head = this->head->nxtPtr;
        return val;
    }

    void print(void)
    {
        Node<int>* cue = this->head;
        while(cue != NULL)
        {
            cout << cue->data << "\t";
            cue = cue->nxtPtr;
        }
        cout << endl;
    }

    T remove(void)
    {
        if (size == 0) return NULL;
        T val = head->data;
        this -> head = head->nxtPtr;
        if( --size == 0) this -> tail = NULL;
        return val;
    }

    bool add(T x)
    {
        Node<T>* u = new Node<T>(x);
        tail->nxtPtr = u;
        this->tail = u;
        if (++size == 1) this->head = u;
        return true;
    }

};







int main(void)
{
    List<int>* a = new List<int>();
    a->push(1);
    a->push(2);
    a->push(12);
    a->print();
    a->pop();
    a->print();
    a->push(121);
    a->print();
    a->push(112);
    a->print();
    a->remove();
    a->print();
    a->add(1000);
    a->print();
    return 0;
}