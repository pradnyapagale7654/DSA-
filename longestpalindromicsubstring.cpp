#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
string longestpalindromicsubstring(string s){
    string ans="";
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){   // for forming the substring
           string sub=s.substr(i,j-i+1) ; // j-i+1= length of substr
           string rev=sub;
           reverse(rev.begin(),rev.end());
           if(sub==rev){ // palindrome
            //but required longest palindrome
            if(sub.size()>ans.size()){
                ans=sub;
            }
           }
        }
    }
    return ans;
}
};
int main(){
    solution s1;
    string s="babad";
    string res=s1.longestpalindromicsubstring(s);
    cout<<"longest palindromic substring is:"<<res;
    return 0;
}