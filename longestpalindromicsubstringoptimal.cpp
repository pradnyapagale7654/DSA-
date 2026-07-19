#include<iostream>
#include<algorithm>
using namespace std;
class solution{
    public:
string lps(string s){
    string ans="";
    int n=s.size();
    int maxlen=1;
    int st=0;
    if(n==0){
        return "";
    }
    for(int i=0;i<n;i++){
       //for odd len palindrome
       int left=i;
       int right=i;
       while(left>=0 && right<n && s[left]==s[right]){
        int len=right-left+1;
        if(len>maxlen){
            maxlen=len;
            st=left;
        }
        left--;
        right++;
       }
       //for even palindrome
       left=i;
       right=i+1;
       while(left>=0 && right<n && s[left]==s[right]){
        int len=right-left+1;
        if(len>maxlen){
            maxlen=len;
            st=left;
        }
        left--;
        right++;
       }
    }
    return s.substr(st,maxlen);
}
};
int main(){
    solution s1;
    string s="babad";
    string res=s1.lps(s);
    cout<<"longest palindromic substring is:"<<res;
    return 0;
}