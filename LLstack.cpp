#include <iostream>
using namespace std;

template<class T> class myNode{
    T data;
    myNode<T> *next;
public:
    myNode<T V>{data=V; next=NULL;}
    myNode(T V,myNode<T> *n){
        data=v;next=n;
    }
    template<class U> friend class myStack;
};

template<class T> class myStack{
    myNode<T> *top;     //pointer to top node
public:
    myStack(){top=NULL;}  //constructor
    ~myStack();         //destructor
    bool empty(){return !top;}
    int hold();          //number of items hold
    void push(T);        //push operation
    T pop();
};

template<class T> myStack<T>::~myStack(){
    while(top){
        myNode<T> *t=top;
        top=top->next;
        delete t;
    }
}
template<class T> int myStack<T>::hold(){
    int h=0;
    myNode<T> *t=top;
    while(t){
        h++;
        t=t->next;
    }
    return h;
}

template<class T> void myStack<T>::push(T V){
    if(!empty())
        top=new myNode<T>(V, top);
    else
    {
        top=new myNode<T>(V);
    }
}

template<class T> T myStack<T>::pop(){
    T V=top->data;
    myNode<T> *t=top;
    top=top->next;
    delete t;
    return V;
}