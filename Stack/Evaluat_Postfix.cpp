#include "Stack.cpp"
#include <iostream>
#include <string>
#include <math.h>

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

int EvaluatePostfix(string s){
    Stack <int> st(s.length());
    int i;
    int x1 ,x2;
    for (i=0;s[i]!= 0;i++){
        if(IsOperand(s[i])) st.Push(s[i] - '0');
        else{
            x2 = st.Pop();
            x1 = st.Pop();

            switch (s[i])
            {
            case '+':
                st.Push(x1+x2);
                break;
            case '-':
                st.Push(x1-x2);
                break;
            case '*':
                st.Push(x1*x2);
                break;
            case '/':
                st.Push(x1/x2);
                break;
            case '^':
                st.Push(pow(x1,x2));
                break;
            
            default:
                break;
            }
        }
    }
    return st.Pop();

}

int main(){
    string s;
    cout<<"Enter a expression : ";
    getline(cin,s);
    int n = s.length();
    cout<<"Postfix Expression ="<<infixToPostfix(s)<<endl;

    cout<<"Answer is "<<EvaluatePostfix(infixToPostfix(s));
    return 0;
}