#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
int duplicate(vector<int>&nums){
  int n=nums.size();
  unordered_map<int,int>freq;
  // find frequency
  for(int i=0;i<n;i++){
    freq[nums[i]]++;
  }
  for(int j=0;j<n;j++){
    if(freq[nums[j]]>1){
        return nums[j];
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