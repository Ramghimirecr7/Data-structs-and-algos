#include <iostream>
using namespace std;

//circular Queue
template<class T> class myQueue{
    T *ptr;            //pointer to storage
    int size;         //size of storage
    int head;             //head position
    int tail;              //tail position
    int hold;        //number of items hold
public:
    myQueue(int);        //constructor
    ~myQueue(){free(ptr);}   //destructor
    bool empty(){return !hold;}
    bool full(){return hold==size;}
    int hold(){return hold;}
    void append(T);       //append operation
    T remove();           //remove operation
};

template<class T> myQueue<T>::myQueue(int s){
    ptr=(T *) malloc(s*sizeof(T));
    size=s;
    hold=head=tail=0;
}

template<class T> void myQueue<T>::append(T V){
    ptr[tail++]=V;
    if(tail>=size)
        tail=0;
    hold++;
}

template <class T> T myQueue<T>::remove(){
    int h=head;
    head++;
    if(head>=size)
        head=0;
    hold--;
    return ptr[h];
}
