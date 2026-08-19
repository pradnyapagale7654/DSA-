#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
bool search(vector<int>&nums,int target){
    // differenece between the search in rotated sorted array 1 and 2 is that in 2 there are duplicates which may lead the problem of identifying which part is sorted 
    int n=nums.size();
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==target){
            return true;
        }
        if(nums[mid]==nums[st] && nums[mid]==nums[end]){
            // duplicate 
            st++;
            end--;
        }
        else if(nums[st]<=nums[mid])
        {
            //left sorted
            if(nums[st]<=target && nums[mid]>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        else{
            //right sorted
            if(nums[mid]<target && nums[end]>=target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return false;
}
};
int main(){
    solution s;
    vector<int>nums={2,5,6,0,0,1,2};
    cout<<s.search(nums,5);
    return 0;
}