#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
int subarraysum(vector<int>&nums,int k){
    int count=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum %k==0){
                count++;
            }
        }
    }
    return count;
}
};
int main(){
    Solution s;
    vector<int>nums={4,5,0,-2,-3,1};
    int k=5;
    int res=s.subarraysum(nums,k);
    cout<<"The number of subarrays with sum divisible by "<<k<<" is: "<<res<<endl;
    return 0;
}