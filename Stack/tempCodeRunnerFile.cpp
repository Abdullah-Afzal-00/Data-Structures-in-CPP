    cout<<"Enter a expression : ";
    getline(cin,s);
    int n = s.length();
    cout<<"Postfix Expression ="<<infixToPostfix(s)<<endl;