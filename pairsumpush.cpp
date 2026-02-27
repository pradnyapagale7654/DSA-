#include<iostream>
#include<vector>
using namespace std;
class student{
    public:
vector<int>pairsum(const vector<int>&nums,int target){
    vector<int>ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return {i,j};
            }
        }
    }
   return {};
}
};
int main(){
    student s;
    vector<int>nums={2,4,3,7,8};
    int target=5;  
    vector<int>ans=s.pairsum(nums,target);
        cout<<ans[0]<<" ,"<<ans[1];
     return 0;
}