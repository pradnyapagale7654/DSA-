#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
int longestconsequtivesequence(vector<int>&nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int count=1;
    int maxcount=1;
    for(int i=0;i<n;i++){
        if(nums[i]-1==nums[i-1]){
            count++;
        }
        else{
            count=1; // Reset count if the current number is not consecutive
        }
        maxcount=max(maxcount,count);
    }
    return maxcount;
}
};
int main(){
    solution s;
    vector<int>nums={100,4,200,1,3,2};
    int res=s.longestconsequtivesequence(nums);
    cout<<"The length of the longest consecutive subsequence is: "<<res<<endl;
    return 0;
}