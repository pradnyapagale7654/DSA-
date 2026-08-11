#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int longestcommonprefixlength(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size();
    int m=arr2.size();
    int maxlen=0;
    for(int x:arr1){
        string s1=to_string(x);
        for(int y:arr2){
            string s2=to_string(y);
            int len=0;
            for(int i=0;i<min(n,m);i++){
                if(s1[i]==s2[i]){
                    len++;
                }
            }
            maxlen=max(maxlen,len);
        }
    }
    return maxlen;
}
};
int main(){
    solution s;
    vector<int>arr1={123,456,789};
    vector<int>arr2={12,34,56};
    cout<<s.longestcommonprefixlength(arr1,arr2);
        
    return 0;
}