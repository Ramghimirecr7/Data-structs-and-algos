#include <iostream>
using namespace std;

template<class T> class myNode{
    T data;        //data part
    myNode<T> *prev, *next;
public:
    myNode(T V){
        data=v; prev=next=this;
    }
    myNode(T V,myNode *p, myNode* n){
        data=v; prev=p; next=n;
    }
    template<class U> friend class myDCList;
};

template <class T> class myDCList{
    myNode<T> *head;
public:
    myDCList(){head=NULL;}  //constructor
    ~myDCList();            //destructor
    bool empty(){return !head;}  //empty or not
    int length();            //list length
    void add(T)             //add to head
    void append(T);         //append to tail
    void remove(T);         //remove a value
}

template <class T> myDCList<T>::~myDCList{
    if(head){
        myNode<T> *h=head;
        while(h->next!=head){
            myNode<T> *C=h;
            h=h->next;
            delete C;
        }
        delete h;
    }
}

template<class T> void myDCList<T>::add(T V){
    if(!empty()){
        myNode<T> *tail=head->prev;
        head=new myNode<T>(V, tail, head);
        head->next->prev=head;
        tail->next=head;
    }
    else{
        head=new myNode<T>(V);
    }
}

template <class T> void myDCList<T>::append(T V){
    if(!empty()){
        myNode<T> *tail=head->prev;
        head->prev=new myNode<T>(V, tail, head);
        tail->next=head->prev;
    }
    else{
        head=new myNode<T>(V);
    }
}

template<class T> void myDCList<T>::remove(T V){
    if(!empty()){
        myNode<T> *c=head;
        while(c->next!=head&&c->data!=V){
            c=c->next;
        }
        if(c->data==V){         //adjust link
            if(c->prev==c && c->next==c)//c is the only node
                head=NULL;
            else if(c->prev=head){//c is the second node
                head->next=c->next;
                c->next->prev=head;
            }
            else if(c->next==head){//c is the tail
                head->prev=c->prev;
                c->prev->next=head;
            }
            else{//c is between two nodes
                c->prev->next=c->next;
                c->next->prev=c->prev;
            }
            delete c;
        }
    }
}