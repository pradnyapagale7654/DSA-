#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n;i++){
            if(nums[i]!=i){
                return i;
            }
        } 
        return n;
    }
};
int main(){
    Solution s;
    vector<int>nums={3,0,1};
    int ans=s.missingNumber(nums);
    cout<<ans;
    return 0;
}