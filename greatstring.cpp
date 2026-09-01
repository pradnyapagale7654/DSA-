#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class solution{
    public:
string greatstring(string s){
    int n=s.length();
    stack<char>st;
    for(int i=0;i<n;i++){
       if(!st.empty() && abs(st.top()-s[i])==32){ // ASCII difference between uppercase and lowercase letters is 32
           st.pop();
       }
       else{
              st.push(s[i]);
       }
    }
    string result = "";
    while (!st.empty()) {
        result +=st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
};
int main(){
    solution s;
    string str="leEeetcode";
    string result=s.greatstring(str);
    cout<<"The great string after removing adjacent pairs is: "<<result<<endl;
    return 0;
}