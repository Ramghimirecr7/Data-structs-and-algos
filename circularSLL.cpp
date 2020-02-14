#include <iostream>
using namespace std;

template <class T> class myNode{
    T data;
    myNode<T> *next;
public:
    myNode(T V){
        data=V; next=this;
    }
    myNode(T V, myNode *n){
        data=V; next=n;
    }
    template <class U> friend class myCList;
};

template <class T> class myCList{
    myNode<T> *head;
public:
    myCList(){head=NULL;}   //constructor
    ~myCList();             //destructor
    bool empty(){return !head;}
    int length();           //length of list
    void add(T);            //add to head
    void append(T);          //append to tail
    void remove(T);              //remove a value
};

template <class T> myCList<T>::~myCList(){
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

template <class T> int myCList<T>::length(){
    int len=0;
    if(head){
        myNode<T> *h=head;
        len++;
        while(h->next!=head){
            h=h->next;
            len++;
        }
    }
    return len;
}

template <class T> void myCList<T>::add(T V){
    if(!empty()){
        myNode<T> *t=head;
        while(t->next!=head){
            t=t->next;
        }
        head=new myNode<T>(V, head);
        t->next=head;
    }
    else
    {
        head=new myNode<T>(V);
    }
}

template <class T> void myCList<T>::append(T V){
    if(!empty){
        myNode<T> *t=head;
        while(t->next!=head){
            t=t->next;
        }
        t->next=new myNode<T>(V, head);
    }
    else
    {
        head=new myNode<T>(V);
    }
    
}

template <class T> void myCList<T>::remove(T V){
    if(!empty){
        myNode<T> *p=NULL, *c=head;
        while(c->next!=head&&c->data==V){
            p=c; 
            c=c->next;
        }
        if(c->data==V){
            //if we find target
            if(!p){//c is head
                myNode<T> *t=c;
                while(t->next!=head)
                    t=t->next;
                head=c->next;
              t->next=head;
            }
            else{
                p->next=c->next;
            }
            delete c;
        }
    }
}