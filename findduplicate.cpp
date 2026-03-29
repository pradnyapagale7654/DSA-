#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int duplicate(vector<int>&nums){
  int n=nums.size();
  for(int i=0;i<n;i++){
    int freq=0;
    for(int j=0;j<n;j++){
        if(nums[i]==nums[j]){
            freq++;
        }
    }
    if(freq>1){
        return nums[i];
    }
  }
  return -1;
}
};
int main(){
    solution s;
    vector<int>nums={1,2,6,4,9,8,2};
    int result=s.duplicate(nums);
    cout<<"duplicate number is:"<<endl;
    cout<<result;
    return 0;
}