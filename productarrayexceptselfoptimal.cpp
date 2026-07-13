#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    vector<int>product(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n,1);
        // finding the product of prefix elements
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        // finding the product of suffix elements
        int suffix=1;
        for(int i=n-2;i>=0;i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;
        }
        return ans;

    }
};
int main(){
    solution s;
    vector<int>nums={1,2,3,4};
    vector<int>ans=s.product(nums);
    for(auto num:ans){
        cout<<num<<" ";
    }
    return 0;
}