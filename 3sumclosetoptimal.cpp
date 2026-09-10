#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
int threesumcloset(vector<int>&nums,int target){
    int n=nums.size();
    int closet=nums[0]+nums[1]+nums[2]; // Initialize closet with the sum of the first three elements
    sort(nums.begin(),nums.end()); // Sort the array to use two-pointer technique
    int sum=0;
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            sum=nums[i]+nums[j]+nums[k];
            if(abs(sum-target)<abs(closet-target)){
                closet=sum; // Update closet if the current sum is closer to the target
            }
            if(sum<target){
                j++; // Move the left pointer to the right to increase the sum
            }
            else if(sum>target){
                k--; // Move the right pointer to the left to decrease the sum
            }
            else{
                return sum; // If the sum is equal to the target, return it immediately
            }
        }
    }
    return closet; // Return the closest sum found
}
};
int main(){
    solution s;
    vector<int>nums={-1,2,1,-4};
    int target=1;
    int res=s.threesumcloset(nums,target);
    cout<<"The closest sum to the target is: "<<res<<endl;
    return 0;
}