#include <iostream>

using namespace std;

int Fibnaouci(int n){
    if (n<=1) return n;
    else return Fibnaouci(n-2) + Fibnaouci(n-1);
}


int main(){
    cout<<Fibnaouci(5);
    return 0;
}