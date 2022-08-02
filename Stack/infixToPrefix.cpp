#include "Stack.cpp"
#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

void swap(char& a , char& b ){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

string Reverse(string& s, int h , int l){
    if ( l < h){
        swap(s[l],s[h]);
        Reverse(s,h-1,l+1);
    }
    return s;
}

bool IsOperand(char x){
    if(x == '+' or x == '-' or x == '*' or x == '/' or x == '^' or x == '(' or x == ')') return false;
    else return true;
}

int outPrecedence(char x){
    if(x == '+' or x == '-') return 1;
    else if (x == '*' or x == '/') return 3;
    else if (x == '^') return 6;
    else if (x == '(') return 7;
    else if (x == ')') return 0;
    else return -1; 
}
int inPrecedence(char x){
    if(x == '+' or x == '-') return 2;
    else if (x == '*' or x == '/') return 4;
    else if (x == '^') return 5;
    else if (x == '(') return 0;
    //else if (x == ')') return 0;
    else return 0; 
}

string infixToPostfix(string infix){
    Stack <char> st(infix.length());

    string postfix = "";

    int i = 0 , j = 0;

    while(infix[i] != 0){
        if(IsOperand(infix[i])) postfix += infix[i++];
        else {
        if (outPrecedence(infix[i]) > inPrecedence(st.Top())) st.Push(infix[i++]);
        else{
            if(st.Top() == '(') {
                st.Pop();
                i+=1;
            }
            else postfix += st.Pop();
        }
        }
    }

    while(!st.IsEmpty()){
        postfix += st.Pop();
    }
    return postfix;
}
int main(){
    string s;
    int i;
    cout<<"Enter a expression : ";
    getline(cin,s);
    cout<<"First Reverse = "<<Reverse(s,s.length()-1,0)<<endl;
    for(i=0;i<s.length();i++){
        if(s[i]==')') s[i] = '(';
        else if(s[i] == '(') s[i] = ')';
    }
    cout<<"Brackets Changed = "<<s<<endl;
    string rs = infixToPostfix(s);
    cout<<"Postfix Expression ="<<infixToPostfix(s)<<endl;
    Reverse(rs,rs.length()-1,0);
    cout<<"Prefix Expression ="<<rs;
    return 0;
}