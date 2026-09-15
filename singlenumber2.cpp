#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    public:
    int singlenumber2(vector<int>&nums){
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto x:mp){
            if(x.second==1){
                return x.first;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int>nums={2,2,3,2};
    int res=s.singlenumber2(nums);
    cout<<"The single number is: "<<res<<endl;
    return 0;
}