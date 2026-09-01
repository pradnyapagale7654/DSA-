#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class solution{
    public:
string clearDigits(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && isdigit(s[i])){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main(){
    solution s;
    string str="a1b2c3d4";
    string result=s.clearDigits(str);
    cout<<"The string after removing digits is: "<<result<<endl;
    return 0;
}
