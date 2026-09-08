#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    public:
    int subarraysumdividek(vector<int>&nums,int k){
        int count=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=1;
        for(int num:nums){
            sum+=num;
            int mod=((sum%k)+k)%k;
            if(mp.find(mod)!=mp.end()){
                count+=mp[mod];
            }
            mp[mod]++;
        }
        return count;   
    }
};
int main(){
    Solution s;
    vector<int>nums={4,5,0,-2,-3,1};
    int k=5;
    int res=s.subarraysumdividek(nums,k);
    cout<<"The number of subarrays with sum divisible by "<<k<<" is: "<<res<<endl;
    return 0;
}