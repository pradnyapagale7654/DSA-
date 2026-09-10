#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class solution{
    public:
  int threesumcloset(vector<int>&nums,int target){
    int n=nums.size();
    int closet=nums[0]+nums[1]+nums[2]; // Initialize closet with the sum of the first three elements
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                sum=nums[i]+nums[j]+nums[k]; // Calculate the sum of the current triplet
                if(abs(sum-target)<abs(target-closet)){
                    closet=sum; // Update closet if the current sum is closer to the target
                }
            }
        }
    }
    return closet;
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