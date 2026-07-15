#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
bool isalphanum(char c){
    if((c>='0'&& c<='9') || (tolower(c)>='a' && tolower(c)<='z')){
        return true;
    }
    return false;
}
bool validpalindrome(string s){
    int n=s.length();
    int st=0;
    int end=n-1;
    while(st<end){
       if(!isalphanum(s[st])){
        st++;
        continue;
       }
       if(!isalphanum(s[end])){
        end--;
        continue;
       }
       if(tolower(s[st])!=tolower(s[end])){
        return false;
       }
       st++;
       end--;
    }
    return false;
}
};
int main(){
    solution s;
    string str="A man, a plan, a canal: Panama";
    bool ans=s.validpalindrome(str);    
    cout<<ans;
    return 0;
}