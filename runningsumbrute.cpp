#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n);
        int cs=0;
        for(int i=0;i<n;i++){
            cs+=nums[i];
            ans[i]=cs;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4};
    vector<int> result=s.runningSum(nums);
    cout<<"The running sum of the array is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}