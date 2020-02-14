//myStack.cpp
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

template<class T> class myStack{
    T *ptr;          //pointer to storage
    int size;        //size of storage
    int top;         //top position
public:
    myStack(int);    //constructor
    ~myStack(){free(ptr);} //destructor
    bool empty(){return top==-1;}
    bool full(){return top==size-1;}
    int hold(){return top +1;}//how many elements stack can hold
    void push(T V){ptr[++top]=V;}
    T pop(){return ptr[top--];}
    void display(int);
};

template<class T> myStack<T>::myStack(int s){
    ptr=(T *)malloc(s*sizeof(T));
    size=s;
    top=-1;
}

template<class T>void  myStack<T>::display(int m){
    if(!empty()){
        cout<<"Stack Element: "<<endl;
        int j=0;
        for(int i=top;i>=0;i--){
            cout<<"t"<<ptr[i];
            j++;
            if(j%m==0)
                cout<<endl;
        }
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}

int main(){
    myStack<char> cs(64);
    myStack<int> is(32);
    const int m=8;
    srand((unsigned) time(NULL));
    cout<<"Characters pushed onto cs: "<<endl;
    int i=0;
    while(i<64){
        char c=rand()%26+65;
        cs.push(c);
        cout<<"\t"<<c;
        i++;
        if(i%m==0)
            cout<<endl;
    }
    //create random integer stack in a similar way
    cs.display(m);
    is.display(m);
    return 0;
}