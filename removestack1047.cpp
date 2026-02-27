#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
    public:
        string removeDuplicates(string s) {
            int n=s.size();
            stack<char>st;
            vector<char>ans;
          
            for(int i=0;i<n;i++){
                if(!st.empty() && s[i]==st.top()){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            string result(ans.begin(),ans.end());
            return result;
        }
    };