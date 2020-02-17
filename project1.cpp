//Ram Ghimire
//200133902
//project1.cpp

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Process{                            //pseudo process structure
    int id;                                //pseudo process identifier
    int priority;                          //pseudo process priority
};

class pNode{                               //process node class
    Process *ptr;                          //pointer to a process
    pNode *next;                           //pointer to next node

public:
    pNode(Process *p){                      //constructor
        ptr=p; next=NULL;
    }
    pNode(Process *p, pNode *n){            //constructor
        ptr=p;next=n;
    }
    friend class pQueue;
};

//define pQueue class here
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

void pQueue::insert(Process *ptr){		// insert a process complying with its priority
     if(!empty()){
         pNode *p=NULL, *c=head;
         while(c && c->ptr->priority<=ptr->priority){	// find the position to insert
			p=c; c=c->next;
         }
         if(!p)										// ptr has the highest priority
			head=new pNode(ptr, head);
         else if(!c)								// ptr has the lowest priority
			p->next=new pNode(ptr);
         else										// insert between
			p->next=new pNode(ptr, c);
     }
     else
         head=new pNode(ptr);
}

Process *pQueue::get(){
    pNode *h=head;
    Process *ptr=h->ptr;
    head=head->next;
    delete h;
    return ptr;
}

void pQueue::display(){								// display process information in the queue
    if(head){
 	cout<<"Process Information:"<<endl;
     	pNode *h=head;
     	while(h){
	      cout<<"Process id ="<< h->ptr->id <<"\t"<<"Priority="<<h->ptr->priority<<endl;
	      h=h->next;
     	}
    }
    else
		cout<<"Queue is empty."<<endl;
}


int main(int argc, char*argv[]){                   //program entrance
    int n=atoi(argv[1]);                           //number if pseudo processes
    Process p[n];                                  //pseudo process array
    srand((unsigned) time(NULL));                  //set random seed
    pQueue q;                                      //priority queue

    for(int i=0;i<n;i++){                          //setup priority queue with random priority
        p[i].id=i+1;                               //pseudo process id
        p[i].priority=rand()%8;                    //pseudo process priority, o is the highest priority
        q.insert(&p[i]);                           //insert pseudo process into priority queue
    }
    q.display();                                   //display priority queue
    return 0;
}