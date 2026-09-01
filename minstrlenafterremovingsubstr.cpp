#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class solution{
    public:
int minlengthafterremovingsubstr(string s){
    int n=s.length();
    stack<char>st;
    for(int i=0;i<n;i++){
        if(!st.empty() && ((st.top()=='A' && s[i]=='B') || (st.top()=='C' && s[i]=='D'))){
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
    reverse(res.begin(), res.end());
    return res.length();
}
};
int main(){
    solution s;
    string str="ABCDAB";
    int result=s.minlengthafterremovingsubstr(str);
    cout<<"The minimum length of the string after removing adjacent pairs is: "<<result<<endl;
    return 0;
}