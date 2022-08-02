#include "Stack.cpp"
#include <iostream>
#include <string>

using namespace std;



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
    cout<<"Enter a expression : ";
    getline(cin,s);
    int n = s.length();
    cout<<"Postfix Expression ="<<infixToPostfix(s);
    return 0;
}