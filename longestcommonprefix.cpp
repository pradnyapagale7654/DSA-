#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
string longestCommonPrefix(vector<string>& strs) {
    string ans="";
    for(int i=0;i<strs[0].length();i++){
        char c=strs[0][i];
        for(int j=1;j<strs.size();j++){
            if(i >= strs[j].length() ||c!=strs[j][i]){
                return ans;
            }
        }
         ans += c;
        
    }
    return ans;
}
};
int main(){
    solution s;
    vector<string>strs={"flower","flow","flp"};
    string res=s.longestCommonPrefix(strs);
    cout<<res;
    return 0;
}