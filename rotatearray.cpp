#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
void rotatearray(vector<int>&nums,int k){
    int n=nums.size();
    k%=n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}
};
int main(){
    vector<int>nums={1,2,3,4,5,6,7};
    int k=3;
    solution s;
    s.rotatearray(nums,k);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}