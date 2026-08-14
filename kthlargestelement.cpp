#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class solution{
    public:
int kthlargestelement(vector<int>&nums,int k){
    int n=nums.size();
    priority_queue<int,vector<int>,greater<int>>pq;  //min heap
    for(int s:nums){
        pq.push(s);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}
};
int main(){
    solution s;
    vector<int>nums={3,1,6,9,4};
    int k=3;
    int ans=s.kthlargestelement(nums,k);
    cout<<"kth largest element is:"<<ans;
    return ans;
}