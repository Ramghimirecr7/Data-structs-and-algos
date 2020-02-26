#include <iostream>
using namespace std;

//stack and queue as derived class
template <class T> class myNode{
    T data;
    myNode<T> *next;
    public:
        myNode(T V){data=V; next=NULL;}
        myNode(T V, myNode<T> *n){
            data=V; next=n;
        }
        template <class u> friend class myList;
};
template<class T> class myList{
    myNode<T> *head;
    public:
        myList(){head=NULL;}
        ~myList();
        bool empty(){return !head;}
        int length();
        void add(T); //add to head
        void append(T); //append to tail
        T remove(); //get from head
};

template<class T> myList<T>::~myList(){
    while(head){
        myNode <T> *h=head;
        head=head->next;
        delete h;
    }
}
template <class T> int myList<T>::length(){
    int len=0;
    myNode<T> *h=head;
    while(h){
        len++;
        h=h->next;
    }
    return len;
}

template <class T> void myList<T>::add(T V){
    if(!empty()){
        head=new myNode<T>(V, head);
    }
    else
    {
        head=new myNODE<t>(v);
    }
}
template <class T> void myList<T>::append(T V){
    if(!empty()){
        myNode<T> *t=head;
        while(t->next)
            t=t->next;
        t->next=new myNode<T>(V);
    }
}

template<class T> T myList<T>::remove(){
    T V=head->data;
    myNode<T> *h=head;
    head=head->next;
    delete h;
    return V;
}

//derived stack class from myList
template <class T> myStack:public myList<T>{
    public:
        myStack():myList<T>(){}
        ~myStack():~myList<T>(){}
        bool empty(){return myList<T>::empty();}
        int length(){return myList<T>::length();}
        void push(T V){myList<T>::add(V);}
        T pop(){return myList<T>::remove();}
};

//derived queue class from myList
template <class T> myQueue:public myList<T>{
    public:
        myQueue():myList<T>(){}
        !myQueue():~myList<T>(){}
        bool empty(){return myList<T>::empty();}
        int length(){return myList<T>::length();}
        void append(T V){myList<T>::append(V);}
        T remove(){return myList<T>::remove();}
};