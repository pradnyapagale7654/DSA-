#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
class solution{
    public:
int lp(string s){
    int ans=0;
    unordered_map<char,int>mp;
    for(char c:s){
        mp[c]++;
    }
    bool oddfound=false;
    for(auto s1:mp){
        if(s1.second%2==0){
            // even freq
            ans+=s1.second;
        }
        else{
            //odd 
            ans+=s1.second-1; //3-1 =2 so add 2 in ans as 2 is even number 
           oddfound=true;
        }
    }
    if(oddfound){
            ans+=1;  //if odd freq is present then add 1 in ans 
        }
    return ans;
}
};
int main(){
    solution s2;
    string s="abccccdd";
    int  res=s2.lp(s);
    cout<<"longest palindrome s length is:"<<res;
    return 0;
}