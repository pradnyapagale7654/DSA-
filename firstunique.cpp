#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
    public:
    int firstunique(string s){
        unordered_map<char,int>mp;
        int n=s.length();
        for(char c:s){
            mp[c]++;
        }
        // traverse and check whose freq is 1 and return the index of that char
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int result=s.firstunique(str);
    if(result==-1){
        cout<<"No unique character found."<<endl;
    }
    else{
        cout<<"The index of the first unique character is: "<<result<<endl;
    }
    return 0;
}