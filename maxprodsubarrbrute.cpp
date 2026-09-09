#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prod;
        int maxprod=INT_MIN;
        for(int i=0;i<n;i++){
            prod=1;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                maxprod=max(maxprod,prod);
            }
        }
        return maxprod;
    }
};
int main(){
    Solution s;
    vector<int>nums={2,3,-2,4};
    int res=s.maxProduct(nums);
    cout<<"The maximum product of a subarray is: "<<res<<endl;
    return 0;
}