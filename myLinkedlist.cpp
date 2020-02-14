// Ram Ghimire
// 200133902
// myLinkedlist.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T> 
class myNode { 					 // node class

	T data;						 // data
	myNode<T> * next;			 // Pointer to the next node
public:
	myNode(T v){
		data = v;				  
		next = NULL;
		}
	myNode(T v, myNode<T> *n){
		data = v;
		next = n;
	}
	template <class U> friend class myList;
};
template <class T> class myList {
	
	myNode<T> * head;
public:
	
	myList( ) {                  // consturctor
	    head = NULL;
	}					
	~myList(){                   // destructor
	    while(head){
	        myNode<T> *h = head;
	        head = head -> next;
	        delete h;
	    }
	}					 
	
	bool empty() {               // empty or not
	    return !head;
	}
	int length();                // length of list
	void add (T v);              // add to head
	void append (T v);           // append to tail
	void display(int m);         // display, m elements per line
};
template <class T>
int myList<T>:: length(){
    int count =0;
    myNode<T> *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
template <class T>
void myList<T>::add(T v){
    // if empty
    if (empty())
    head = new myNode<T>(v);
    else
        head = new myNode<T>(v, head);
}
template <class T>
void myList<T>:: append (T v){
    
    if (empty())
        head = new myNode<T>(v);
    else
    {
        myNode<T> *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new myNode<T>(v);
    }
}
template <class T>
void myList<T>:: display(int m){
    int count =0;
    myNode<T> *p = head ;
    while (p != NULL)
    {
        count++; 
        cout << p-> data << "\t" ;
        if(count% m == 0)
            cout << endl;
        p = p->next;
    }
    cout << endl;
}
int main( int argc, char* argv[]) {
    int nc = atoi(argv[1]);  //char list dimension
    int ni = atoi(argv[2]);  //int list dimension
    myList<char> clist;      //char list
    myList<int> ilist;         //int list
    
    const int m = 8;         //eight elements per line
    srand((unsigned) time(NULL));
    
    // create character list and display all entries
    int i = 0;
    while (i < nc) {
        char c = rand() % 26 + 65;
        clist.add(c);
        cout << "\t" << c;
        i++;
        if(i%m == 0)
            cout << endl;
    }
    cout << endl;
    
    // create integer list and display all entries
    i = 0;
    while (i < ni) {
        int v = rand()% 256;
        ilist.append(v);
        cout << "\t" << v;
        i++;
        if(i%m == 0)
            cout << endl;
    }
    cout << endl;
    
    clist.display(m);
    ilist.display(m);
     
    return 0;
    }