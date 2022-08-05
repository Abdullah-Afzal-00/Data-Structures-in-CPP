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
};

template <class T>
class Linked_List{
    Node<T>* head;
    Node<T>* tail;
public:
    Linked_List(){
        head = tail = NULL;
    }
bool isEmpty(){
    if(head == NULL or tail == NULL) return true;
    else return false;
}
void addHead( T data){
    if (head == NULL or tail == NULL ){
        head = new Node<T>;
        tail = head;
        head->data = data;
        //cout<<"It's head data = "<<head->data<<endl;
    }
    else{
        Node<T>* temp = head;
        head = new Node<T>;
        head->data = data;
        head->next = temp;
        //delete temp;
    }
}
void addTail( T data){
    if (head == NULL or tail == NULL ){
        tail = new Node<T>;
        head = tail;
        tail->data = data;
        //cout<<"It's Tail Data = "<<tail->data<<endl;
    }
    else{
        Node<T>* temp = tail;
        tail = new Node<T>;
        tail->data = data;
        temp->next = tail;
        //cout<<"It's Tail Data = "<<tail->data<<endl;
        //delete temp;
    }
}

void display(){
    if(isEmpty()) cout<<"Linked List is Empty\n";
    else {
        Node<T>* temp = head;
        // cout<<head->data<<endl;
        // cout<<temp->data;
        while(temp->next != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
        cout<<"Head = "<<head->data<<" Tail = "<<tail->data<<endl;
        //delete temp;
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
         Node<T>* temp = head;
         head = head->next;
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
         Node<T>* temp1 = head;
         Node<T>* temp2 ;

         while(temp1->next != NULL){
            temp2 = temp1;
            temp1 = temp1->next;
         }
         
         tail = temp2;
         tail->next = NULL;
         delete temp1;
    }
}

void deleteNode (int pos){
     if(isEmpty()) cout<<"Linked List is Empty";
    if(pos == 1) deleteHead();
    else {
        int i;
        Node<T>* temp1 = head;
        Node<T>* temp2;
        for(i=0;i<pos-1 and temp1;i++){
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if(temp1 == tail) deleteTail();
        else if(temp1){
            temp2->next = temp1->next;
            delete temp1;
        }
        else cout<<"Not a valid Index";
    }
}

void sortedInsert(T data ){
    if(head == NULL or data <= head->data ) addHead(data);
    else {
        Node<T>* p = head;
        Node<T>* q = NULL;
        while(p and p->data < data){
            q = p;
            p = p->next;
        }
        if(p == NULL) addTail(data);
        else {
            Node<T>* t = new Node<T>;
            t->data = data;
            t->next = q->next;
            q->next = t;
        }
    }
}

Node<T>* search(T data){
    Node<T>* p = head;
    while(p != NULL){
        if(p->data == data ) return p;
        p = p->next;
    }
    return NULL;
}

void insertNode(T data , int pos){
    if(pos == 1) addHead(data);
    else{
        Node<T>* temp1 = head;
        Node<T>* newElement = new Node(data);
        int i;
        for(i=0 ;i<pos-2 and temp1 ;i++)
            temp1 = temp1->next;
        if(temp1){
            if(temp1 == tail) tail = newElement;
            newElement->next = temp1->next;
            temp1->next = newElement;
        }
        else cout<<"Linked List has only "<<i<<" Elements. Give index according to that range of Elements ( 1 to "<<i+1<<" )"<<endl;
        
    }
}
};


int main(){
    Linked_List<int> l1;
    // l1.addHead(8);
    // l1.addTail(10);
    // l1.addHead(50);
    // l1.addTail(90);
    // l1.display();
   //l1.deleteHead();
    //l1.deleteTail();
    //l1.deleteNode(4);

    l1.sortedInsert(30);
    l1.sortedInsert(5);
    l1.sortedInsert(10);
    l1.sortedInsert(12);

    //     Node<int>* s;
    // s = l1.search(100);
    // if(s == NULL ) cout<<"\nNot Found\n";
    // else cout<<"\nFound\n";
    l1.display();
    return 0;
}