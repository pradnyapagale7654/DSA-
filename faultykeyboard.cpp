#include<iostream>
#include<algorithm>
using namespace std;
class solution{
    public:
string faulty(string s){
    string ans="";
    for(char c:s){
        if(c=='i'){
            reverse(ans.begin(),ans.end());
        }
        else{
            ans.push_back(c);
        }
    }
    return ans;
}
};
int main(){
    solution s;
    string result=s.faulty("string");
    cout<<result;
    return 0;
}