#include <iostream>

using namespace std;

int Combination(int n,int r){
    if(n == 0 or r==0 or n == r) return 1;
    return Combination(n-1 , r-1) + Combination(n-1,r);
}

int main(){
    cout<<Combination(4,2);
    return 0;
}