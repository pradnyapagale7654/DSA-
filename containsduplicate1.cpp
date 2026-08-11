#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
bool isduplicate(vector<int>&nums){
    int n=nums.size();
    unordered_map<int,int>mp;
    // count the frequency of each element in the array
    for(int x:nums){
        mp[x]++;
    }
    //check if frequency of any element is greater than 1
    for(auto it:mp){
        if(it.second>1){
            return true;
        }
    }
    return false;
}
};
int main(){
    solution s;
    vector<int>nums={1,2,3,4,5};
    if(s.isduplicate(nums)){
        cout<<"The array contains duplicate elements."<<endl;
    }
    else{
        cout<<"The array does not contain duplicate elements."<<endl;
    }
    return 0;
}