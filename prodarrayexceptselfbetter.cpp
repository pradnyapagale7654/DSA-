#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
vector<int>product(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n,1);
    vector<int>prefix(n,1);
    vector<int>suffix(n,1);
     
    // finding the product of prefix elements
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*nums[i-1];
    }

    // finding the product of suffix elements
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*nums[i+1];
    }
    // multiply prefix with suffix
    for(int i=0;i<n;i++){
        ans[i]=prefix[i]*suffix[i];
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