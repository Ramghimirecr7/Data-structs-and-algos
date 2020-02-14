//singly linked list
#ifndef T_LINKED_LIST
#define T_LINKED_LIST

template <class T> class myNode{
    T data;         //data member
    myNode<T> *next;   //pointer to next
public:
myNode(T V){data=v; next=NULL;}
myNode(T V, myNode *n){
    data =v; next=n;
}
template <class U> friend class myList;
};

template <class T> class myList{
    myNode<T> *head;  //head pointer
public:
    myList(){head=NULL;}  //constructor
    ~myList();             //destructor
    bool empty(){return !head;}   //empty or not
    int length();          //return length
    void add(T);         //add to head
    void append(T);         //append to tail
    T remove();     //remove from head
    bool find(T)         //find a value
    void delete(T);       //delete a value
    void display(int);     //display elements
};

#endif