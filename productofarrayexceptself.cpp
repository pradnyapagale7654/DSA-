#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
vector<int>productarray(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int prod=1;
        for(int j=0;j<n;j++){
            if(i!=j){
                prod*=nums[j];
            }
        }
        ans[i]=prod;
    }
    return ans;
}
};
int main(){
    solution s;
    vector<int>nums={1,2,3,4};
    int n=4;
    vector<int>ans= s.productarray(nums);
    cout<<"result is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    return 0;
}