#include<iostream>
#include<stack>
using namespace std;
bool isoperator(char c){
    if(c=='+' || c=='-'||c=='*'||c=='/'){
        return true;
    }
    return false;
}

string prefixtoinfix(string s){
    stack<string>st;
    for(int i=s.length()-1;i>=0;i--){
    char c=s[i];
    if(isalnum(c)){
        string op(1,c);
        st.push(op);
    }
   
    else if(isoperator(c)){
        if(st.size()<2){
         cout<<"invalid";
        }
        string t1=st.top();
        st.pop();
        string t2=st.top();
        st.pop();
        st.push("("+t2+s[i]+t1+")");
        }
    
    else{
        cout<<"invalid expression:";
    }
}
    if(st.empty()){
        cout<<"stack is empty";
    }
    return st.top();
}
int main(){
    cout<<prefixtoinfix("+45");
    return 0;
}