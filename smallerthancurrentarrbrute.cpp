#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
vector<int>smallerthancurrent(vector<int>&nums){
    vector<int>ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[i]>nums[j]){
                count++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}
};
int main(){
    solution s;
    vector<int>nums={8,1,2,2,3};
    vector<int>res=s.smallerthancurrent(nums);
    cout<<"The count of numbers smaller than current number is: ";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}