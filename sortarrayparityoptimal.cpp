#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    vector<int>sortarray(vector<int>&nums){
        int n=nums.size();
        int st=0;
        int end=n-1;
        while(st<end){
            if(nums[st]%2==0){
                st++;
            }
            else if(nums[end]%2==1){
                end--;
            }
            else{
                swap(nums[st],nums[end]);
                st++;
                end--;
            }
        }
        return nums;
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