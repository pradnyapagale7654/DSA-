#include<iostream>
#include<stack>
#include<string>
using namespace std;
class solution{
    public:
    stack<char>st;
    bool ispalindrome(string s){
        for(int i=0;i<s.length();i++){
           st.push(s[i]);
        }
        for(int i=0;i<s.length();i++){
            if(s[i]!=st.top()){
                return false;
            }
            else{
                st.pop();
            }
        }
        return true;
    }
};
int main(){
    solution a;
   cout<<a.ispalindrome("madam");
   return 0;
}