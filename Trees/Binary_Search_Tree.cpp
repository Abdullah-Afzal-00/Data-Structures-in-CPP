#include<iostream>
#include "queue.cpp"
#include "Stack.cpp"

using namespace std;

template <class T>
class DLNode{

public:
    T data;
    DLNode* left;
    DLNode* right;

    DLNode(){
        data = -1;
        left = NULL;
        right = NULL;
    }
    DLNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

template <class T>

class BinarySearchTree{
    DLNode<T>* root = NULL;
public:
    BinarySearchTree(){
        root = NULL;
    }
// Insert Function    
void insert(T data){
    DLNode <T>* t = root;
    DLNode <T>* r;
    if(root == NULL){
        DLNode <T>* p = new DLNode<T>;
        root = p;
        p->data = data;
        p->left = p->right = NULL;
        return;
    }
    while(t != NULL){
        r = t;
        if(data < t->data) t = t->left;
        else if(t->data < data) t = t->right;
        else return;
    }
     DLNode <T>* p  = new DLNode<T>;
    p->data = data;
    p->left = p->right = NULL;

    if(data<r->data) r->left = p;
    else r->right = p;
}
void inOrder(DLNode<T>* p){
    if(p){
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
}
//Getter of Root;
DLNode<T>* getRoot(){
    return root;
}
//Setter of Root;
void setRoot(DLNode<T>* p){
    root = p;
}
//Getter of Data
T getData(DLNode<T>* p){
    if(p == NULL) return NULL;
    return p->data;
}
//Calculate height of tree;
int height(DLNode<T>* p ){
    if (p == NULL) return 0;
    int x , y;
    x = height(p->left);
    y = height(p->right);

    // if(x>y) return x+1;
    // else return y+1;
    return x>y ? x+1 : y+1;
}

//Inorder Predescor 
DLNode<T>* InPre(DLNode<T>* p){
    while(p and p->right != NULL)
        p = p->right;
    
    return p;
}

//InOrder Succesor
DLNode<T>* InSuc(DLNode<T>* p){
    while(p and p->left != NULL)
        p = p->left;
    
    return p;
}

//Search Function for Node;
DLNode<T>* search(T data){
    DLNode<T>* p = root;
    while(p != NULL){
        if(p->data == data) return p;
        else if(p->data < data) p = p->right;
        else p = p->left;
    }
    return NULL;
}

//Recursive Isert
DLNode<T>* Rinsert(DLNode<T>* p, T data ){
    if(p == NULL){
        DLNode<T>* t = new DLNode<T>;
        t->data = data;
        t->left = t->right = NULL;
        return t;
    }
    if(data < p->data)
        p->left = Rinsert(p->left , data);
    else if(data > p->data)
        p->right = Rinsert(p->right , data);
    
    return p;
}
//Create from oreOrder
void createFromPre(int* a , int n){
    Stack<DLNode<T>*> st(100);
    DLNode<T>* t;
    int i = 0 ;
    root = new DLNode<T>;
    root->data = a[i++];
    root->left = root->right=NULL;
    DLNode<T>* p = root;
        while(i<n){
            if(p == NULL ) p = root;
            if(a[i] < p->data){
                t = new DLNode<T>;
                t->data = a[i++];
                t->left = t->right = NULL;
                p->left = t;
                st.Push(p);
                p = t;
            }
            else{
                auto temp = st.Pop();
                if(a[i] > p->data and temp !=NULL and  a[i] < temp->data){
                    t = new DLNode<T>;
                    t->data = a[i++];
                    t->left = t->right = NULL;
                    p->right = t;
                    p = t;
                }
                else p = temp;
            }
        }
}

//Deletion of a Node
DLNode<T>* deleteNode(DLNode<T>* p ,T data ){
    if(p == NULL) return NULL;
    if(p->right == NULL and p->left == NULL){
        if(p == root) root == NULL;
        delete p;
        return NULL;
    }
    if(data < p->data)
        p->left = deleteNode(p->left , data);
    else if(data > p->data)
        p->right = deleteNode(p->right , data);
    else{
        if(height(p->left) > height(p->right)){
            DLNode<T>* q =  InPre(p->left);
            p->data = q->data;
            p->left =deleteNode(p->left,q->data);
        }
        else{
            DLNode<T>* q = InSuc(p->right);
            p->data = q->data;
            p->right = deleteNode(p->right,q->data);
        }
    }
    return p;
}
};

int main(){
    BinarySearchTree<int> tree1;
    //Iterative Insertion
    tree1.insert(10);
    tree1.insert(5);
    tree1.insert(20);
    tree1.insert(8);
    tree1.insert(30);

    // int a[8] = {30,20,10,15,25,40,50,45};
    // tree1.createFromPre(a , 8);              ---------->Maintenance Required

    //Recursive Insertion
    // tree1.setRoot(tree1.Rinsert(tree1.getRoot() ,  10));
    // tree1.Rinsert(tree1.getRoot() ,  5);
    // tree1.Rinsert(tree1.getRoot() ,  20);
    // tree1.Rinsert(tree1.getRoot() ,  8);
    // tree1.Rinsert(tree1.getRoot() ,  30);

    tree1.inOrder(tree1.getRoot());
    
    tree1.deleteNode(tree1.getRoot() , 20);
    
    cout<<endl;
    tree1.inOrder(tree1.getRoot());
    cout<<tree1.getData(tree1.search(30));
    if(tree1.getData(tree1.search(30))) cout<<"\nFound";
    else cout<<"\nNot Found";

    return 0;
}