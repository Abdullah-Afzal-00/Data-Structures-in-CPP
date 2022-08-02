#include <iostream>
#include "queue.cpp"

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

class BinaryTree{
    DLNode<T>* root = NULL;
    Queue<DLNode<T>*>* q;
public:
    BinaryTree(){
        DLNode <T>* p ;
        q = new Queue<DLNode<T>*> (100);
        root = new DLNode<T>;
        T x;
        cout<<"Enter root value ";
        cin>>x;
        root->data = x;
        root->left = root->right = NULL;
        q->enqueue(root);

        while(!q->isEmpty()){
            p = q->dequeue();
            cout<<"Enter Left child of "<<p->data<<" : ";
            cin>>x;
            if(x != -1){
                 DLNode <T>* t = new DLNode<T>;
                t->data = x;
                t->left = t->right = NULL;
                p->left = t;
                q->enqueue(t);
            }
            cout<<"Enter Right child of "<<p->data<<" : ";
            cin>>x;
            if(x != -1){
                 DLNode <T>* t = new DLNode<T>;
                t->data = x;
                t->left = t->right = NULL;
                p->right = t;
                q->enqueue(t);
            }

        }

        
    }

void preOrder(DLNode<T>* p){
    if(p){
        cout<<p->data<<" ";
        preOrder(p->left);
        preOrder(p->right);
    }
}
void inOrder(DLNode<T>* p){
    if(p){
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
}
DLNode<T>* getRoot(){
    return root;
}
void levelOrder(DLNode<T>* p){
    q = new Queue<DLNode<T>*> (100);
    cout<<p->data<<" ";
    q->enqueue(p);
    while(!q->isEmpty()){
        p = q->dequeue();
        if(p->left){
            cout<<p->left->data<<" ";
            q->enqueue(p->left);
        }
        if(p->right){
            cout<<p->right->data<<" ";
            q->enqueue(p->right);
        }
    }
}
int count(DLNode<T>* p){
    int x , y;
    if(p != NULL){
        x = count(p->left);
        y = count(p->right);
        return x+y+1;
    }
    else return 0;
}
int countLeafNodes(DLNode<T>* p){
    int x , y;
    if(p != NULL){
        x = countLeafNodes(p->left);
        y = countLeafNodes(p->right);
        if(p->left == NULL and p->right ==NULL) return x+y+1;
        else return x+y;
    }
    else return 0;
}
int countInternalNodes(DLNode<T>* p){
    int x , y;
    if(p != NULL){
        x = countInternalNodes(p->left);
        y = countInternalNodes(p->right);
        if(p->left != NULL or p->right !=NULL) return x+y+1;
        else return x+y;
    }
    else return 0;
}
int countDegree2Nodes(DLNode<T>* p){
    int x , y;
    if(p != NULL){
        x = countDegree2Nodes(p->left);
        y = countDegree2Nodes(p->right);
        if(p->left != NULL and p->right !=NULL) return x+y+1;
        else return x+y;
    }
    else return 0;
}
int countDegree1Nodes(DLNode<T>* p){
    int x , y;
    if(p != NULL){
        x = countDegree2Nodes(p->left);
        y = countDegree2Nodes(p->right);
        if(p->left != NULL ^ p->right !=NULL) return x+y+1;
        else return x+y;
    }
    else return 0;
}
int heightCount(DLNode<T>* p){
    int x ,y;
    if(p!=NULL){
        x = heightCount(p->left);
        y = heightCount(p->right);
        if(x>y) return x+1;
        else return y+1;
    }
    else return 0;
} 

};
int main(){
    BinaryTree<int> tree1;
    tree1.preOrder(tree1.getRoot());
    cout<<endl;
    tree1.inOrder(tree1.getRoot());
    cout<<endl;
    tree1.levelOrder(tree1.getRoot());
    cout<<endl;
    cout<<tree1.count(tree1.getRoot());
    cout<<endl;
    cout<<tree1.countLeafNodes(tree1.getRoot());
    cout<<endl;
    cout<<tree1.countInternalNodes(tree1.getRoot());
    cout<<endl;
    cout<<tree1.countDegree2Nodes(tree1.getRoot());
    cout<<endl;
    cout<<tree1.heightCount(tree1.getRoot());
    return 0;
}