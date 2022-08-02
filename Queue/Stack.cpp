#ifndef STACK
#define STACK

#include <iostream>

using namespace std;

template <class T>

class Stack{
    T* stack;
    int capacity;
    int top;

public:
    Stack(int capacity){
        this->capacity = capacity;
        stack = new T[capacity];
        top =-1;
    }

    Stack(){top =-1;}

void setCapacity(int x){

    this->capacity = capacity;
    stack = new T[capacity];
}

bool IsEmpty(){
    if(top == -1) return true;
    else return false;
}
bool IsFull(){
    if(top == capacity-1) return true;
    else return false;
}

void Push(T x){
    if(! this->IsFull()) stack[++top] = x;
    else cout<<"\nstack is Full";

}
T Pop(){
    if(this->IsEmpty()){
        //cout<<"stack is Empty.";
        return -1;
    }
    else return stack[top--];
}

T Top(){
    if( this->IsEmpty()){
        //cout<<"stack is Empty.";
        return -1;
    }
    else return stack[top];
}

};


// int main(){

//     Stack <int> s(2);
//     s.Push(150);
//     cout<<s.Pop()<<endl;
//     cout<<s.Top()<<endl;
//     cout<<s.Pop();
//     s.Push(22);
//     s.Push(33);
//     s.Push(40);
//     s.Push(90);

//     return 0;
// }

#endif