#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
int firstidx(string haystack,string needle){
    if(haystack.size()<needle.size()){
        return -1;
    }
    for(int i=0;i<=haystack.size()-needle.size();i++){
        string s=haystack.substr(i,needle.size());
        if(s==needle){
            return i;
        }
    }
    return -1;
}
};
int main(){
    solution s;
    string haystack="sadbutsad";
    string needle="but";
    int ans=s.firstidx(haystack,needle);
    cout<<"first index is at:"<<ans;
    return 0;
}