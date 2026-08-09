#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        char sums=0;
        for(int i=0;i<s.length();i++){
            sums^=s[i];
        }
        for(int j=0;j<t.length();j++){
            sums^=t[j];
        }
        return sums;
    }
};
int main(){
    Solution s;
    string str1,str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    char result=s.findTheDifference(str1,str2);
    cout<<"The extra character in the second string is: "<<result<<endl;
    return 0;
}