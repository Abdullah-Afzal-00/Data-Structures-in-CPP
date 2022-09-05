#include "Linked_List.cpp"
#include <iostream>
using namespace std;

template <class T>
class HashTable{
    Linked_List<T>** hashArray;
    int size ;
public:
    HashTable(int size){
        int i ; 
        hashArray = new Linked_List<T>*[size];
        for(i = 0 ; i < size ; i++ )
            hashArray[i] = new Linked_List<T>;
    }
T hash(T data){
    return data%10;
}
void insert(T data){
    T index = hash(data);
    //cout<<index;
    hashArray[index]->sortedInsert(data);
     //cout<<" Here in Hash Insert ";
    //hashArray[index]->display();
}
Node<T>* search(T data){
    T index = hash(data);
    return hashArray[index]->search(data);
}};

int main(){
    //cout<<"Hello Ji";
    HashTable<int> h(10);
    h.insert(10);
    h.insert(50);
    h.insert(20);
    // if(h.search(29) == NULL) cout<<"Not Founed";
    // else cout<<"Founed";
    //cout<<"End Of Programme ";
    return 0;
}