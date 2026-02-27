#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    vector<vector<int>>foursum(vector<int>nums,int target){
     vector<vector<int>>ans;
     int n=nums.size();
     sort(nums.begin(),nums.end());
     for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]){  //skip duplicate fori
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]){ // skip duplicates for j
                continue;
            }
            int p=j+1;
            int q=n-1;
            while(p<q){
                long long sum=(long long) nums[i]+(long long) nums[j]+(long long) nums[p]+(long long) nums[q];
                if(sum>target){
                    q--;
                }
                else if(sum<target){
                    p++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                    p++;
                    q--;
                    while(p<q && nums[p]==nums[p-1]){
                        p++;     //skip duplictaes for p
                    }
                    while(p<q && nums[q]==nums[q+1]){
                        q--;    //skip duplictaes for q
                    }
                }
            }
        }
     }
     return ans;
    }
};
int main(){
    solution s;
    vector<int>nums={-2,-1,-1,1,1,2,2};
    int target=0;
    return 0;
}