#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    int sumof(vector<int>&nums,int st,int end){
        int sum=0;
        for(int i=st;i<=end;i++){
            sum+=nums[i];
        }
        return sum;
    }
    int pivotindex(vector<int>&nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
            int leftsum=sumof(nums,0,i-1);
            int rightsum=sumof(nums,i+1,n-1);
            if(leftsum==rightsum){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int result=s.pivotindex(nums);
    if(result!=-1){
        cout<<"The pivot index is: "<<result<<endl;
    }
    else{
        cout<<"There is no pivot index in the array."<<endl;
    }
    return 0;
}