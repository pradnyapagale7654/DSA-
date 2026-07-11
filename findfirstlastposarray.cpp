#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
//using linear search tc=o(n)
vector<int> findposition(vector<int>&nums,int target){
    int n=nums.size();
    int first=-1;
    int last=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==target){
           if(first==-1){
            first=i;
           }
           last=i;
        }
    }
    return {first,last};
}
};
int main(){
    solution s;
    vector<int>nums={5,7,7,8,8,10};
    int target=8;
    vector<int>ans=s.findposition(nums,target);
    cout<<"first position is "<<ans[0]<<" last position is "<<ans[1];
    return 0;
}