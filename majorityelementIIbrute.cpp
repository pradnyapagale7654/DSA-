#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    vector<int>majorityelement(vector<int>&nums){
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count>n/3){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
int main(){
    solution s;
    vector<int>nums={3,2,3};
    vector<int>ans=s.majorityelement(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}