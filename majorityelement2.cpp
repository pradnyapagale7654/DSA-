#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
vector<int>majorityelement(vector<int>&nums){
    int n=nums.size();
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    for(auto it:mp){
        if(it.second>n/3){
            ans.push_back(it.first);
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