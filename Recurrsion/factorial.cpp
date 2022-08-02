#include <iostream>

using namespace std;

int factorial(int n){
    if(n==0) return 1;
    else return factorial(n-1) *n ;
}

int factorial2(int n){
    int ans=1;
    while(n>0){
        ans*=n;
        n-=1;
    }
    return ans;
}

int main(){
    cout<<factorial(6)<<endl;
    cout<<factorial2(6);
    return 0;
}