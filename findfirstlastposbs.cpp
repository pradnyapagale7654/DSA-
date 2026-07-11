#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    int findfirst(vector<int>&nums,int target){
        int n=nums.size();
        int ans=-1;
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }

        }
        return ans;
    }
    int findlast(vector<int>&nums,int target){
        int n=nums.size();
        int ans=-1;
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                ans=mid;
                st=mid+1;
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
vector<int>findrange(vector<int>&nums,int target){
    int first=findfirst(nums,target);
    int last=findlast(nums,target);
    return {first,last};
}
};
int main(){
    solution s;
    vector<int>nums={5,7,7,8,8,10};
    int target=8;
    vector<int>ans=s.findrange(nums,target);
    cout<<"first position is "<<ans[0]<<" last position is "<<ans[1];
    return 0;
}