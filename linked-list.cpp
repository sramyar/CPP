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
        this -> nxtPtr = nullptr;
    }
};

template<class T>
class List{

    public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    List():head(0),tail(0),size(0){};
    List(T data[], int n){
        size = 0;
        head = tail = nullptr;
        for(int i=0; i<n; i++){
            try
            {
                add(data[i]);
            }
            catch(const std::exception& e)
            {
                this->add(NULL);
            }         
        }
    }

    List(List<T>* l, bool deep = false)
    {
        if(deep){
            Node<T>* cue = l->head;
            this->head=nullptr;
            this->tail=nullptr;
            this->size=0;
            while(cue != nullptr){
                add(cue->data);
                cout << "added: "<< cue->data <<endl;
                cue = cue->nxtPtr;
            }
        }
        else
        {
            this->head = l->head;
            this->tail = l->tail;
            this->size = l->size;
        }
        
    }

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
        Node<T>* cue = this->head;
        while(cue != NULL)
        {
            cout << cue->data << "\t";
            cue = cue->nxtPtr;
        }
        cout << endl;
    }
    /*
    bool remove(T element)
    {
        if(size==0) return false;
        Node<T>* cue = head;
        if(size==1){
            head = tail = nullptr;
            --size;
            return true;
        }
        while (cue->nxtPtr != nullptr){
            if(cue->nxtPtr->data == element){
                if(cue->nxtPtr == tail){
                    tail = cue;
                    tail->nxtPtr = nullptr;
                }
                else
                    cue->nxtPtr = cue->nxtPtr->nxtPtr;
                --size;
                return true;
            }
            else
            {
                cue = cue->nxtPtr;
            }
            
        }
        return false;
    }
    */
    bool hasElement(T element)
    {
        Node<T>* cue = head;
        while(cue != nullptr){
            if(cue->data == element) return true;
            cue = cue->nxtPtr;
        }
        return false;
    }

    int getIndex(T target)
    {
        Node<T>* cue = head;
        int index = 0;
        while (cue != nullptr){
            if(cue->data == target) return index;
            ++index;
            cue = cue->nxtPtr;
        }

        return -1;
    }

    Node<T>* getElement(int index)
    {
        Node<T>* cue = head;
        for(int i=0; i<index; i++){
            cue = cue->nxtPtr;
        }
        return cue;
    }

    T remove(void)
    {
        if (size == 0) return NULL;
        T val = head->data;
        this -> head = head->nxtPtr;
        if( --size == 0) this -> tail = nullptr;
        return val;
    }

    bool remove(int idx)
    {
        Node<T>* targetNode = getElement(idx);
        if(size==1 && idx==0){
            head = tail = nullptr;
            --size;
            return true;
        }
        if(idx == 0 && size>1){
            head = targetNode->nxtPtr;
            --size;
            return true;
        }

        Node<T>* cue = head;
        for(int i=0; i < idx-1; i++){
            cue = cue->nxtPtr;
        }
        if(cue->nxtPtr==tail) tail = cue;
        cue -> nxtPtr = cue ->nxtPtr ->nxtPtr;
        
        --size;
        return true;
        
    }

    bool add(T x)
    {
        Node<T>* u = new Node<T>(x);
        if (this->size == 0){
            this->head = u;
            this->tail = u;
        }
        else{
            tail->nxtPtr = u;
            this->tail = u;
        }
        ++this->size;
        return true;
    }

    bool isEmpty()
    {
        return (head==nullptr && tail==nullptr && size == 0);
    }

    Node<T>* findMinElement()
    {
        T min = head->data;
        Node<T>* Min = head;
        Node<T>* cue = head;
        while(cue != nullptr){
            if(cue->data < min) {
                min = cue->data;
                Min = cue;
            }
            cue = cue->nxtPtr;
        }
        return Min;
    }

    int minElementIndex()
    {
        Node<T>* min = this->findMinElement();
        int index = this->getIndex(min->data);
        return index;
    }
    /*
    ~List()
    {
        cout << "destructor called for " << this;
        for(tail = head; tail != NULL;){
            tail = head->nxtPtr;
            delete head;
            --size;
            head = tail;
        }
        --size;
    }
    */

    

};

template<class T>
void printList(Node<T>* cue)
    {
        if(cue==nullptr)return;
        cout << cue->data << ", ";
        printList(cue->nxtPtr);
    }

template<class T>
ostream& operator<<(ostream& out, List<T>* l)
{
    out << "List of size: " << l->size << endl;
    return out;
}

/*
int main(void)
{
    int data[] = {1,2,3,4,5};
    List<int> l(data,9);
    l.print();
    cout << &l;
    char c[] = {'k','i','r','i'};
    List<char> cl(c,4);
    cl.remove('i');
    cout << "has element 'k'? " << cl.hasElement('k') << endl;
    cout << "has element 'a'? " << static_cast<int>(cl.hasElement('a')) << endl;
    cl.print();
    cout << &cl;
    List<char> cl2(&cl,true);
    cl2.print();
    cout << &cl2 << endl;
    cout << "Bytes in a list: " <<sizeof cl2 <<endl;
    cout << "Bytes in a list of ints: " << sizeof(List<int>) << endl;
    cout << "Bytes in a list of doubles: " << sizeof(List<double>) << endl;
    cout << "Bytes in a list of chars: " << sizeof(List<char>) << endl;
    cout << "Bytes in a list of strings: " << sizeof(List<string>) << endl;
  
    return 0;
}

*/


