#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
int subarraysum(vector<int>&nums,int k){
    int count=0;
    int n=nums.size();
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    for(int num:nums){
        sum+=num;
        if(mp.find(sum-k)!=mp.end()){
            count+=mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
}
};
int main(){
    solution s;
    vector<int>nums={1,1,1};
    int k=2;
    int res=s.subarraysum(nums,k);
    cout<<"The number of subarrays with sum equal to "<<k<<" is: "<<res<<endl;
    return 0;
}