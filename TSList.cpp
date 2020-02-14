#include <iostream>
#include <ctime>
#include "TSList.h"
using namespace std;

template <class T> myList<T>::~myList(){
    while(head){
        myNode<T> *h=head;
        head=head->next;
        delete h;
    }
}

template <class T> int myList<T> ::length(){
    int len=0;
    myNode<T> *h=head;
    while(h){
        len++;
        h=h->next;
    }
    return len;
}

template <class T> void myList<T>::add(T V){
    if(!length())
        head = new myNode<T>(V, head);
    else
        head= new myNode<T>(V); 
}

template <class T> void myList<T>::append(T V){
    if(!empty()){
        myNode<T> *t=head;
        while(t->next)
            t=t->next;
        t->next=new myNode<T>(V);
    }
    else
    {
        head=new myNode<T>(V);
    }
} 

template <class T> T myList<T>::remove(){
    myNode<T> *h=head;
    T V=h->data;
    head=head->next;
    delete h;
    return V;
}

template <class T> bool myList<T>::find(T V){
    if(empty())
        return false;
    else{
        myNode<T> ptr=head;
        while (ptr)
        {
            if(ptr->data==v)
                return true;
            else
            {
                ptr=ptr->next;
            }
            
        }
        return false;
    }
}

template <class T> void myList<T>::delete(T V){
    if(!empty()){
        myNode<T> *P=NULL, *C=head;
        while(C && C->data !=V){
            P=C;
            C=C->next;
        }
        if(C){
            if(!P)       //C is head
                head=C->next;
            else
                P->next=C->next;
            delete C;
        }
    }
}