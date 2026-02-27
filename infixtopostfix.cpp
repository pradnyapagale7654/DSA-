#include<iostream>
#include<stack>
using namespace std;
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'|| c=='/'){
        return 2;
    }
    else if(c=='+'|| c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
  

string infixtopostfix(string s){
    stack<char>st;
    string res;
    for(int i=0;i<s.length();i++){
        if(isalnum(s[i])){
            res=res+s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
            res=res+st.top();
            st.pop();
        }
        //When you encounter ')', you correctly pop until '(', but you did not pop the '(' itself.
        if(!st.empty()){
            st.pop();
        }
    }
        else{
            //operator
             while(!st.empty()&&  prec(st.top())>=prec(s[i])){
                res=res+st.top();
                st.pop();
             }
             st.push(s[i]);
        }
    }
    while(!st.empty()){
        res=res+st.top();
        st.pop();
    }
    return res;
}
int main(){
    cout<<infixtopostfix("a+b*c");
    return 0;
}