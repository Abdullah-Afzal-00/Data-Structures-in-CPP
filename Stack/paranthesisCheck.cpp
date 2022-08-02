#include "Stack.cpp"
#include <iostream>
#include <string>

using namespace std;

bool ParanthesisCheck(string e){
    int l = e.length();
    Stack <char> st(l);

    int i;
    for(i=0;e[i] != 0 ;i++){
        if(e[i] == '(') st.Push(e[i]);
        else if(e[i] == ')' and st.Pop() != NULL) st.Pop();
        else if(e[i] == ')') return false;
    }
    if(st.IsEmpty()) return true;
    else false; 
}

int main(){
    string s;
    cout<<"Enter a expression : ";
    getline(cin,s);
    int n = s.length();
    if(ParanthesisCheck(s)) cout<<"Correct";
    else cout<<"Incorrect";
    return 0;
}