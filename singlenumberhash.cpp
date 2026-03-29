#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class solution{
    public:
int singlenumber(vector<int>&nums){
   int n=nums.size();
  unordered_map<int,int>freq;
  //frequency
  for(int i=0;i<n;i++){
    freq[nums[i]]++;
  }
  for(int j=0;j<n;j++){
    if(freq[nums[j]]==1){
        return nums[j];
    }
  }
  return -1;
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