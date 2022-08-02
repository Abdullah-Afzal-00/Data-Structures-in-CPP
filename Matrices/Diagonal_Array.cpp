#include <iostream>

using namespace std;

class DiagonalMatrix{
    int* m;
    int n;

public:
    //Constructors
    DiagonalMatrix(){}

    DiagonalMatrix(int n){
         m = new int[n];
         this->n = n;
        int i;
        for(i=0;i<n;i++)
            this->m[i] = 0; 
    }

    DiagonalMatrix(int* ma, int nu){
        m = new int[nu];
        n = nu;
        int i;
        for(i=0;i<nu;i++)
            this->m[i] = ma[i]; 
    }

    //Setters
void Set(int i, int j, int x){
    if(i == j) m[i] = x;
}
    //Getters
int Get(int i , int j){
    if(i == j) return m[i];
    else return 0;
}
    //Cout Operator

friend ostream& operator << (ostream& out , const DiagonalMatrix& matrix){
    int i,j;
    for(i =0;i<matrix.n;i++){
        for(j=0;j<matrix.n;j++){
            if(i == j) cout<<matrix.m[i]<<" ";
            else cout<<0<<" ";
        }
    cout<<endl;
    }
    return out;
}

    //Destructor

~DiagonalMatrix(){
    delete[] m;
}
};

int main(){
    int a[5] = {2,3,6,7,8};
    DiagonalMatrix dm(a,5);
    cout<<dm;

    cout<<dm.Get(0,0)<<endl;
    dm.Set(0,0,10);
    cout<<dm.Get(0,0);
    return 0;
}