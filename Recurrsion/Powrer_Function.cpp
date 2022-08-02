#include <iostream>

using namespace std;

int Power(int m,int n){
    if(n==0) return 1;
    else return Power(m,n-1)*m;
}
int FastPower(int m , int n){
    if(n==0) return 1;
    if(n%2==0) return FastPower(m*m ,n/2);
    else return m*FastPower(m*m , (n-1)/2);
}

int main(){
    cout<<Power(5,3)<<endl;
    cout<<FastPower(5,3);
    return 0;
}