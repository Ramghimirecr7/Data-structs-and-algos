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

template <Class T> myStack:public myList<T>{
    public:
        myStack():myList<T>(){}
        ~myStack():~myList<T>(){}
        bool empty(){return myList<T>::empty();}
        int length(){return myList<T>::length();}
        void push(T V){myList<T>::add(V);}
        T pop(){return myList<T>::remove();}
};

template <class T> myQueue:public myList<T>{
    public:
        myQueue():myList<T>(){}
        !myQueue():~myList<T>(){}
        bool empty(){return myList<T>::empty();}
        int length(){return myList<T>::length();}
        void append(T V){myList<T>::append(V);}
        T remove(){return myList<T>::remove();}
};