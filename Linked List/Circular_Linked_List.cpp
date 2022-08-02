#include <iostream>

using namespace std;

template <class T>
class Node{
public:
    T data;
    Node* next;

    Node(){
        data = -1;
        next = NULL;
    }
    Node(T data){
        this->data = data;
        next = NULL;
    }
    Node(T data , Node<T>* next ){
        this->data = data;
        this->next = next;
        //cout<<"N "<<this->next<<endl;
    }
};

template <class T>
class CLL{
    Node<T>* tail;

public:
    CLL(){
        tail = NULL;
    }
bool isEmpty(){
    if(tail == NULL) return true;
    else return false;
}
void addTail(T data){
    if(isEmpty()){
        tail = new Node(data);
        tail->next = tail;
        //cout<<tail->data<<endl;
        // Node<T>* temp = tail->next;
        // cout<<"T"<<temp->data;
    }
    else {
        Node<T>* temp = new Node(data , tail->next);
        tail->next = temp;
        tail = temp;
        //cout<<tail->data<<endl;
    }
}

void addHead(T data){
    if(isEmpty()){
        tail = new Node(data);
        tail->next = tail;
    }
    else{
        Node<T>* temp = new Node(data , tail->next);
        tail->next = temp;

    }
}

void removeTail(){
    if(tail->next == tail){
        delete tail;
        tail = NULL;
    }
    else {
         Node<T>* it = tail;
    while(it->next != tail)
        it = it->next;
        
    Node<T>* temp = it->next;
    it->next = tail->next;
    tail = it;

    delete temp;
    }
}
void removeHead(){
    if(tail->next == tail){
        delete tail;
        tail = NULL;
    }
    else{
        Node<T>* temp = tail->next;
        tail->next = tail->next->next;
        delete temp;
    }
}
void insetElement(T data , int pos){
    if(pos == 1) addHead(data);
    else{
        int i;
        bool isOutOfIndex = false;
        Node<T>* temp = new Node(data);
        Node<T>* it = tail;
        for(i=0;i<pos-1;i++){
            it = it->next;
            if(it == tail->next and i>0){
                cout<<"Out of index\n";
                isOutOfIndex = true;
            }
        }if(!isOutOfIndex){
            if(it == tail) addTail(data);
            else{
                temp->next = it->next;
                it->next = temp;
        }
        }
    }
}
void deleteElement(int pos){
    if(pos == 1) removeHead();
    else{
        int i;
        bool isOutOfIndex = false;
        Node<T>* temp;
        Node<T>* it = tail;
        for(i=0;i<pos-1;i++){
            it = it->next;
            if(it == tail and i>0){
                cout<<"Out of index\n";
                isOutOfIndex = true;
            }
        }if(!isOutOfIndex){
            if(it->next == tail) removeTail();
            else{
                temp = it->next;
                it->next = it->next->next;
                delete temp;
        }
        }
    }
}

void display(){
    if(isEmpty()) cout<<"Circular Linked List is Empty\n";
    else{
        //Node<T>* tempTail = this->tail;
        Node<T>* temp = tail->next;
        //cout<<temp->data<<endl;
        while(temp->next != tail->next){
            cout<<temp->data<<" ";
            temp = temp->next;
            //cout<<"End Loop = "<<temp->data;
        }
        cout<<tail->data;
        cout<<endl;
        cout<<"Tail = "<<tail->data<<endl;
    } 
}
};

int main(){
    CLL<int> l1;
    l1.addTail(20);
    l1.addTail(57);
    l1.addTail(12);
    l1.addTail(100);
    l1.display();
    //l1.removeHead();
    l1.deleteElement(4);
    // l1.addHead(50);
    l1.display();
    return 0;
}