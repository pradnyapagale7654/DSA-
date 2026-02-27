#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class solution{
    public:
    vector<vector<int>>threesum(vector<int>&nums){
        vector<vector<int>>ans;
        set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>trip={nums[i],nums[j],nums[k]};
                        sort(trip.begin(),trip.end());
                        if(s.find(trip)==s.end()){
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
