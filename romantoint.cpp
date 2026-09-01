#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
int romantoint(string s){
    unordered_map<char,int>roman={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(roman[s[i]]<roman[s[i+1]]){
            ans-=roman[s[i]];
        }
        else{
            ans+=roman[s[i]];
        }
    }
    return ans;
}
};
int main(){
    solution s;
    string str="MCMXCIV";
    int result=s.romantoint(str);
    cout<<"The integer value of the Roman numeral "<<str<<" is: "<<result<<endl;
    return 0;
}