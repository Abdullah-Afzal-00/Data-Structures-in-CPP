#include "Stack.cpp"
#include <iostream>
#include <string>

using namespace std;

bool BracketsCheck(string e){
    int l = e.length();
    Stack <char> st(l);

    int i;
    char temp;
    for(i =0 ;e[i] != 0 ;i++){
        if(e[i] == '(' or e[i] == '{' or e[i] == '[') st.Push(e[i]);
        if(e[i] == ')' or e[i] == '}' or e[i] == ']'){
            if (e[i] == ')'){
                temp = st.Pop();
                if(temp!= '(') return false;
                //st.Pop();
            }
            else if (e[i] == '}'){
                temp = st.Pop();
                if(temp != '{') return false;
                //st.Pop();
            }
            else if(e[i] == ']'){
                temp = st.Pop();
                if(temp != '[') return false;
                //st.Pop();
            }
        }
    }

    if(st.IsEmpty()) return true;
    else false;
}

int main(){
    string s;
    cout<<"Enter a expression : ";
    getline(cin,s);
    int n = s.length();
    if(BracketsCheck(s)) cout<<"Correct";
    else cout<<"Incorrect";
    return 0;
}