#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class solution{
    public:
bool isduplicate(vector<int>&nums,int k){
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j] && abs(i-j)<=k){
                return true;
            }
        }
    }
    return false;
}
};
int main(){
    solution s;
    vector<int>nums={1,2,3,1};
    int k=3;
    cout<<s.isduplicate(nums,k);
        
    return 0;
}