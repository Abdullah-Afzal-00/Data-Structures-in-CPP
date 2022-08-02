#ifndef QUEUE
#define QUEUE

#include <iostream>

using namespace std;

template <class T>

class Queue{
    T* q;
    int capacity;
    int rearPointer;
    int frontPointer;

public:
    Queue(int capacity){
        this->capacity = capacity;
        q = new T[capacity];
        rearPointer = -1;
        frontPointer = -1;
    }
bool isFull(){
    if(rearPointer >= capacity-1) return true;
    else return false;
}
bool isEmpty(){
    if(rearPointer == frontPointer ) return true;
    else return false;
}
void enqueue(T x){
    if(isFull()) cout<<"queue is filled, No more elemnt can be added.\n";
    else q[++rearPointer] = x;
}
T dequeue(){
    if(isEmpty()){
        cout<<"queue is empty, No elemnt can be extracted.\n";
        return NULL;
    }
    else return q[++frontPointer];
}
T checkFront(){
    if(isEmpty()){
        cout<<"queue is empty, No elemnt is at Front.\n";
        return -1;
    }
    else return q[frontPointer+1];
}
T checkRear(){
    if(isEmpty()){
        cout<<"queue is empty, No elemnt is at rear.\n";
        return -1;
    }
    else return q[rearPointer];
}
};

// int main(){
//     Queue <int> q(3);
//     q.enqueue(25);
//     q.enqueue(34);
//     cout<<q.dequeue()<<endl;
//     q.enqueue(8);
//     q.enqueue(45);
//     cout<<q.checkFront()<<endl;
//     cout<<q.checkRear()<<endl;

//     return 0;
// }

#endif