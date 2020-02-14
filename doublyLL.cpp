#include <iostream>
using namespace std;

template <class T> class myNode{
    T data;
    myNode<T> *prev, *next;
public:
    myNode(T V){//constructor
        data=V; prev=next=NULL;
    }
    myNode( T V, myNode<T> *p, myNode<T> *n){//constructor
        data=V; prev=p; next=n;
    }
    template<class U> friend class myDList;
};

template<class T> class myDList{
    myNode<T> *head;
public:
    myDList(){ head=NULL;}  //constructor
    ~myDList();             //destructor
    bool empty(){return !head};
    int length();           //length of the list
    void add(T);            //add to head
    void append(T);         //append to tail
    void remove(T);         //remove a value  
};

template <class T> myDList<T>::~myDList(){
    while(head){
        myNode<T> *h=head;
        head=head->next;
        delete h;
    }
}

template<class T> int myDList<T>::length(){
    int len=0;
    myNode<T> *h=head;
    while(h){
        len++;
        h=h->next;
    }
    return len;
}

template <class T> void myDList<T>::add(T V){
    if(!empty()){
        myNode<T> *h=head;
        head=new myNode<T> (V, NULL, h);
        h->prev=head;
    }
    else
    {
        head=new myNode<T>(V);
    }
}

template <class T> void myDList<T>::append(T V){
    if(!empty()){
        myNode<T> *t=head;
        while(t->next)
            t=t->next;
        t->next=new myNode<T>(V, t, NULL);
    }
    else
    {
        head=new myNode<T>(V);
    }
}

template <class T> void myDList<T>::remove(T V){
    if(!empty()){
        myNode<T> *c=head;
        while(c&&c->data!=V)
            c=c->next;
        if(c){       //c->data=v
            if(!c->prev&& !c->next)//c is the only node
                head=NULL;
            else if(!c->prev){// c is head
                head=c->next;
                c->next->prev=NULL;
                }
            else if(!c->next)  //c is tail
                c->prev->next=NULL;
            else{//c is between two nodes
                c->prev->next=c->next;
                c->next->prev=c->prev;
            }
            delete c;
        }
    }
}