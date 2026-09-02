#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class solution{
    public:
  string removeoutermostparenthesis(string s){
    string ans="";
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
            if(st.size()>1){
                ans+=s[i];
            }
        }
        else{
            //opening pop
            st.pop();
            if(st.size()>0){
                // not the empty stack
                ans+=s[i];
            }
        }
    }
    return ans;
  }  
};
int main(){
    solution s;
    string res=s.removeoutermostparenthesis("(()())(())");
    cout<<"The string after removing outermost parenthesis is: "<<res<<endl;
    return 0;
}