#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]=='*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    Solution s;
    string res=s.removeStars("leet**cod*e");
    cout<<"The string after removing stars is: "<<res<<endl;
    return 0;
}