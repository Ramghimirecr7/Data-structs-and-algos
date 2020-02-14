#include <iostream>
using namespace std;

template<class T> class myNode{
    T data;
    myNode<T> *next;
    public:
        myNode(T V){data= V; next=0;}
        myNode(T V, myNode<T> *n){
            data=V; next=n;
        }
        template<class U> friend class myList;
};

template<class T> class myList{
    myNode<T> *head;
    public:
        myList(){head=0;}  //constructor
        ~myList();       //destructor
        int length();     //list length
        bool empty(){return !head;} //empty or not
        bool find(T);       //find a value
        void insert(T);       //insert a value
        void remove(T);        //remove a value
};

template <class T> void myList<T>::insert(T V){
    if(!empty()){
        if(!find(V)){
            myNode<T> *p=NULL; *c=head;
            while(!c&&c->data<=V){
                p=c; c=c->next;
            }
            if(!p)          //v is the smallest
                head=new myNode<T>(V, head);
            else if(!c)   //v is the largest
                p->next=new myNode<T>(V)
            else     //v is between two values
                p->next=new myNode<T>(V, c);
        }
    }
    else
        head=new myNode<T>(V);
}