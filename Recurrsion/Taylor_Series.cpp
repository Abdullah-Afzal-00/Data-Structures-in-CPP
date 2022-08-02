#include <iostream>

using namespace std;

double TaylorSeries(int x , int n){
    static double  p = 1 , f = 1;
    double r;
    if(n==0) return 1;
    else {
        r = TaylorSeries(x,n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }
}

double TaylorSeries2(int x , int n){
    static double s = 1;
    if (n == 0 ) return s;
       s = 1+ x*s/n;
       return TaylorSeries2(x,n-1);
}

int main(){

    cout<<TaylorSeries(2,10)<<endl;
    cout<<TaylorSeries2(2,10);
    return 0;
}