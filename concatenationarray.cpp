#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
vector<int>concatenate(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(2*n);
    for(int i=0;i<n;i++){
        ans[i]=nums[i];
        ans[i+n]=nums[i];
    }
    return ans;
}
};
int main(){
    solution s;
    vector<int> nums={1,2,3};
    vector<int> result=s.concatenate(nums);
    cout<<"The concatenated array is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}