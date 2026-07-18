#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
int compress(vector<char>& chars) {
    int n=chars.size();
    string ans="";
    for(int i=0;i<chars.size();){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(chars[i]==chars[j]){
                count++;
            }
            else{
                break;
            }
        }
        ans+=chars[i];
        if(count>1){
            string s=to_string(count);
        for(char c:s){
         ans+=c;
        }
    }
    i+=count;
    }
    return ans.size();
}
};
int main(){
    solution s;
    vector<char>chars={'a','a','b','b','c'};
    int res=s.compress(chars);
    cout<<res;
    return 0;
}