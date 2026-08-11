#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
bool containduplicate(vector<int>&nums,int k){
    int n=nums.size();
    unordered_map<int,vector<int>>mp;
    // push element with their index in the map
    for(int i=0;i<n;i++){
        mp[nums[i]].push_back(i);
    }
    // check if any element has more than one index and the difference between indices is less than or equal to k
    for(auto it:mp){
        vector<int>indices=it.second; // get the indices of the current element store it in vector 
        for(int i=1;i<indices.size();i++){
            if(indices[i]-indices[i-1]<=k){    // as in indices indices are stored in increasing order so we can check the difference between current index and previous index
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
    cout<<s.containduplicate(nums,k);
        
    return 0;
}