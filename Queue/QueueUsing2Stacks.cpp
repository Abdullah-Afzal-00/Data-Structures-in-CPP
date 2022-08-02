#include <iostream>
#include "Stack.cpp"

using namespace std;

template <class T>
class QueueU2S{
     Stack <T> inStack , outStack;
public:
    QueueU2S(int capacity){
        inStack.setCapacity(capacity);
        outStack.setCapacity(capacity);
    }

void enqueue(T x){
    inStack.Push(x);
}
T dequeue(){
    if(inStack.IsEmpty() and outStack.IsEmpty()){
        cout<<"Queue is Empty";
        return -1;
    } 
    else{
        while(!inStack.IsEmpty()){
            outStack.Push(inStack.Pop());
        }
    return outStack.Pop();
    }

}
};

int main(){
    QueueU2S <int> q(3);
    q.enqueue(25);
    q.enqueue(34);
    cout<<q.dequeue()<<endl;
    q.enqueue(8);
    q.enqueue(45);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}