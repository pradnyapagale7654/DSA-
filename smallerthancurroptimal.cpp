#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr=nums;
        sort(arr.begin(),arr.end());
         vector<int> ans;
         for(int x:nums){
            int index=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            ans.push_back(index);
         }
         return ans;
    }
};
int main(){
    Solution s;
    vector<int>nums={8,1,2,2,3};
    vector<int>res=s.smallerNumbersThanCurrent(nums);
    cout<<"The count of numbers smaller than current number is: ";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}