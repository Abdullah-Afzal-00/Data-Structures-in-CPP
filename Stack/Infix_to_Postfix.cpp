#include "Stack.cpp"
#include <iostream>
#include <string>

using namespace std;

bool IsOperand(char x){
    if(x == '+' or x == '-' or x == '*' or x == '/') return false;
    else return true;
}
int Precedence(char x){
    if(x == '+' or x == '-') return 1;
    else if (x == '*' or x == '/') return 2;
    else return 0; 
}

string infixToPostfix(string infix){
    Stack <char> st(infix.length());

    string postfix = "";

    int i = 0 , j = 0;

    while(infix[i] != 0){
        if(IsOperand(infix[i])) postfix += infix[i++];
        else {
        if (Precedence(infix[i]) > Precedence(st.Top())) st.Push(infix[i++]);
        else postfix += st.Pop();
        }
    }

    while(st.Top()!=-1){
        postfix += st.Pop();
    }
    return postfix;
}

int main(){
    string s;
    cout<<"Enter a expression : ";
    getline(cin,s);
   // int n = s.length();
    cout<<"Postfix Expression ="<<infixToPostfix(s);
    return 0;
}