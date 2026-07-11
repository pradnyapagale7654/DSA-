#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
void sortcolors(vector<int>&nums){
    int n=nums.size();
  int st=0;
  int mid=0;
  int end=n-1;
  while(mid<=end){
    if(nums[mid]==0){
        swap(nums[mid],nums[st]);
        st++;
        mid++;
    }
    else if(nums[mid]==2){
        swap(nums[mid],nums[end]);
        end--;
    }
    else{
        mid++;
    }
  }
}
};
int main(){
    solution s;
    vector<int>nums={2,1,2,0,1,0,0,2,0,1,1,2,0,1,2};
    s.sortcolors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;   
}