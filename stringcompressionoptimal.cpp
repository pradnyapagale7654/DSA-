#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
int compress(vector<char>& chars) {
    int n=chars.size();
   int idx=0;
   int i=0;
   while(i<n){
    int count=0;
    int curr=chars[i];
    while(i<n && chars[i] ==curr){
        count++;
        i++;
    }
    chars[idx++]=curr;
    if(count>1){
        string s=to_string(count);
        for(char c:s){
            chars[idx++]=c;
        }
    }
   }
   return idx;
}
};
int main(){
    solution s;
    vector<char>chars={'a','a','b','b','c'};
    int res=s.compress(chars);
    cout<<res;
    return 0;
}