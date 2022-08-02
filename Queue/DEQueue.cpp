#include <iostream>

using namespace std;

template <class T>

class DEQueue{
    T* q;
    int capacity;
    int rearPointer;
    int frontPointer;

public:
    DEQueue(int capacity){
        this->capacity = capacity;
        q = new T[capacity];
        rearPointer = -1;
        frontPointer = -1;
    }
bool isFull(){
    if(rearPointer >= capacity-1 or frontPointer >= capacity-1) return true;
    else return false;
}
bool isEmpty(){
    if(rearPointer == -1 and  frontPointer == -1 ) return true;
    else return false;
}
void Renqueue(T x){
    if(isFull()) cout<<"queue is filled, No more elemnt can be added.\n";
    else q[++rearPointer] = x;
}
void Fenqueue(T x){
    if(isFull()) cout<<"queue is filled, No more elemnt can be added.\n";
    else q[++frontPointer] = x;
}
T Fdequeue(){
    if(isEmpty()){
        cout<<"queue is empty, No elemnt can be extracted.\n";
        return -1;
    }
    else return q[--frontPointer];
}
T Rdequeue(){
    if(isEmpty()){
        cout<<"queue is empty, No elemnt can be extracted.\n";
        return -1;
    }
    else return q[--rearPointer];
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
//Not corrected 
int main(){
    DEQueue <int> q(3);
    q.Fenqueue(25);
    q.Fenqueue(34);
    cout<<q.Rdequeue()<<endl;
    cout<<q.Rdequeue()<<endl;
    q.Renqueue(8);
    q.Renqueue(45);
    cout<<q.checkFront()<<endl;
    cout<<q.checkRear()<<endl;

    return 0;
}