#include<iostream>
#include<stack>
#include<algorithm>
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
string infixtoprefix(string s){
    stack<char>st;
    string res;
    reverse(s.begin(),s.end());
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
            if(!st.empty()){
                st.pop();
            }
        }
   
        else{
            //operator
             while(!st.empty()&& prec(st.top()) >prec(s[i])){
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
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    cout<<infixtoprefix("a+b*c");
    return 0;
}