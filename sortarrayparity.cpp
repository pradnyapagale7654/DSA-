#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    vector<int>sortarray(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n);
        int st=0;
        int end=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                //even placed at the start of ans
                ans[st]=nums[i];
                st++;
            }
            else{
                //odd placed at the last
                ans[end]=nums[i];
                end--;
            }
        }
        return ans;
    }
};
int main(){
    solution s;
    vector<int>nums={3,1,2,4};
    vector<int>result=s.sortarray(nums);
    cout<<"array after sorting even odd numbers:";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}