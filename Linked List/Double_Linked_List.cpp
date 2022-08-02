#include <iostream>

using namespace std;

template <class T>
class DLNode{

public:
    T data;
    DLNode* prev;
    DLNode* next;

    DLNode(){
        data = -1;
        prev = NULL;
        next = NULL;
    }
    DLNode(T data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }

};

template <class T>
class DLinked_List{
    DLNode<T>* head;
    DLNode<T>* tail;

public:
    DLinked_List(){
        head = tail = NULL;
    }

bool isEmpty(){
    if(head == NULL or tail == NULL) return true;
    else return false;
}
void addHead( T data){
    if (head == NULL or tail == NULL ){
        head = new DLNode<T>;
        tail = head;
        head->data = data;
        //cout<<"It's head data = "<<head->data<<endl;
    }
    else{
        DLNode<T>* temp = new DLNode(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
        //delete temp;
    }
}
void addTail( T data){
    if (head == NULL or tail == NULL ){
        tail = new DLNode<T>;
        head = tail;
        tail->data = data;
        //cout<<"It's Tail Data = "<<tail->data<<endl;
    }
    else{
        DLNode<T>* temp = new DLNode(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        //cout<<"It's Tail Data = "<<tail->data<<endl;
        //delete temp;
    }
}

void display(){
    if(isEmpty()) cout<<"Linked List is Empty\n";
    else {
        DLNode<T>* temp = head;
        // cout<<head->data<<endl;
        // cout<<temp->data;
        while(temp->next != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
        //delete temp;
        cout<<"Head = "<<head->data<<" Tail = "<<tail->data<<endl;
    }
}
void deleteHead(){
    if(isEmpty()) cout<<"Linked List is Empty";
    
    else if(head == tail){
        delete head;
        delete tail;
        head = tail = NULL;
    }
    else{
         DLNode<T>* temp = head;
         head = head->next;
         head->prev = NULL;
         delete temp;
    }
}
void deleteTail(){
    if(isEmpty()) cout<<"Linked List is Empty";
    else if(head == tail){
        delete head;
        delete tail;
        head = tail = NULL;
    }
    else{
         DLNode<T>* temp = tail;
         
         tail = tail->prev;
         tail->next = NULL;
         delete temp;
    }
}
void deleteNode (int pos){
    if(isEmpty()) cout<<"Linked List is Empty";
    if(pos == 1) deleteHead();
    else {
        int i;
        DLNode<T>* temp1 = head;
        for(i=0;i<pos-1 and temp1;i++)
            temp1 = temp1->next;

        if(temp1 == tail) deleteTail();
        else if(temp1){
            //DLNode<T>* temp2 = temp1->prev;
            temp1->prev->next = temp1->next;
            temp1->next->prev = temp1->prev;
            delete temp1;
        }
        else cout<<"Not a valid Index"<<endl;
    }
}
void insertNode(T data , int pos){
    if(pos == 0) addHead(data);
    else{
        DLNode<T>* temp1 = head;
        DLNode<T>* newElement = new DLNode(data);
        int i;
        for(i=0 ;i<pos-1 and temp1 ;i++)
            temp1 = temp1->next;
        cout<<"Catch Element = "<<temp1->data<<endl;
        if(temp1){
            if(temp1 == tail){
                addTail(data);
                delete newElement;
            }
            else{
                newElement->next = temp1->next;
                newElement->prev = temp1;
                temp1->next = newElement;
                temp1->next->prev = newElement;

            }
        }
        else cout<<"Linked List has only "<<i<<" Elements. Give index according to that range of Elements"<<endl;
        
    }
}
bool isElementPresent(T data){
    DLNode<T>* temp = head;

    while(temp != NULL ){
        if(temp->data == data) return true;
        temp = temp->next;
    }
    return false;
}
};

int main(){
    DLinked_List<int> l1;
    l1.addTail(85);
    l1.addHead(26);
    l1.addHead(90);
    l1.addHead(30);
    l1.addTail(55);
    l1.display();
    // l1.deleteHead();
    // l1.deleteTail();
    l1.insertNode(100,4);
    if(l1.isElementPresent(98)) cout<<"Yes\n";
    else cout<<"No\n";
    l1.display();
    return 0;
}