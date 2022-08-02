#include <iostream>

using namespace std;

int staticVar(int n){
    int x =0;
    if (n>0){
        x+=1;
        return staticVar(n-1) + x;
    }
    return 0;
}

int main(){
    cout<<staticVar(5);
    return 0;
}