#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int minrotatedsortedarray(vector<int>&nums){
    int n=nums.size();
    int st=0;
    int end=n-1;
    while(st<end){
        int mid=st+(end-st)/2;
        if(nums[mid]>nums[end]) {
            //left sorted ans in right side
            st=mid+1;
        }
        else if(nums[mid]<nums[end]) {
            end=mid;
        }
        else{
             // nums[mid] == nums[end], cannot decide → shrink search space
             end--;
        }
    }
    return nums[st];  // ans always at st position
}
};
int main(){
    solution s;
    vector<int>nums={3,4,5,1,2};
    int ans=s.minrotatedsortedarray(nums);
    cout<<"min in rotated sorted array:"<<ans;
    return 0;
}