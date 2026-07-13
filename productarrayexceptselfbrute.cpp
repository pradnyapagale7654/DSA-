#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    vector<int>product(vector<int>&nums){
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int prod=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    prod*=nums[j];
                }
            }
            ans.push_back(prod);
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