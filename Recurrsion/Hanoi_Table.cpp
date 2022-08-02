#include <iostream>

using namespace std;

void HanoiOf3(int n,int A, int B ,int C){
    if(n>0){
        HanoiOf3(n-1,A,C,B);
        cout<<"Move "<<A<<" To "<<C<<endl;;
        HanoiOf3(n-1,B,A,C);
    }
}

int main(){
    HanoiOf3(5,1,2,3);
    return 0;
}