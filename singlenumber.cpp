#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int singlenumber(vector<int>&nums){
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans=ans^nums[i];
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