#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++){
           ans=ans^i^nums[i];
        } 
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>nums={3,0,1};
    int result=s.missingNumber(nums);
    cout<<result;
    return 0;
}