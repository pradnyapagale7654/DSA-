#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
int singlenumber(vector<int>&nums){
   int n=nums.size();
   int ans=-1;
   for(int i=0;i<n;i++){
    int freq=0;
    for(int j=0;j<n;j++){
        if(nums[i]==nums[j]){
            freq++;
        }
    }
    if(freq==1){
            ans=nums[i];
        }
   }
   return ans;
}
};
int main(){
    solution s;
    vector<int>nums={1,2,2,1,5,6,5};
    int result=s.singlenumber(nums);
    cout<<"single number is:"<<endl;
    cout<<result;
    return 0;
}