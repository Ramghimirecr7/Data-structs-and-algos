#include <iostream>
using namespace std;

struct Process{               //pseudo process
    int id;            //process id
    int priority;         //process priority
};

class pNode{
    Process *ptr;         //pointer to a process
    pNode *next;          //pointer to next node
public:
    pNode(Process *p){ptr=p; next=NULL;}
    pNode(Process *p, pNode *n){
        ptr=p; next=n;
    }
    friend class pQueue;
};

class pQueue{
    pNode *head;         //head pointer
public:
    pQueue(){head=NULL;}    //constructor
    ~pQueue();              //destructor
    bool empty(){return !head;}
    void insert(Process *p); //insert a process
    Process *get();            //get a process
    void display();            //display list
};

pQueue::~pQueue(){
    while(head){
        pNode *h=head;
        head=head->next;
        delete h;
    }
}
void pQueue::insert(Process *p){
    if(!empty()){
        pNode *p=NULL, *c=head;
        while(c&&c->ptr->priority<=p->priority){
            p=c; c->next;
        }
        if(!p)                  //p has the highest priority
            head=new pNode(p, head);
        else if(!c)           //p has lowest priority
            p->next=new pNode(p);
        else 
            p->next=new pNode(p,c);
    }
    else
    {
        head=new pNode(p);
    }
}

Process *pQueue::get(){
    pNode *h=head;
    Process *ptr=h->ptr;
    head=head->next;
    delete h;
    return ptr;
}