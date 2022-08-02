#include <iostream>

using namespace std;

int sumOfNaturalNum(int n){
    if(n== 0) return 0;
    else return sumOfNaturalNum(n-1) +n;
}
int sumOfNaturalNum2(int n){
    return n*(n+1)/2;
}

int main(){

    cout<<sumOfNaturalNum(5)<<endl;
    cout<<sumOfNaturalNum2(5);
    return 0;
}