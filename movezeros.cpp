#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
void movezeros(vector<int>&nums){
    int n=nums.size();
    int st=0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[st]=nums[i];
            st++;
        }
    }
    // fill remaining positions with zeros
    while(st<n){
        nums[st]=0;
        st++;
    }
}
};
int main(){
    solution s;
    vector<int>nums={0,1,0,3,12};
    s.movezeros(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}