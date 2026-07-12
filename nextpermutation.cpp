#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    void nextpermutation(vector<int>&nums){
        //1 find the pivot index
        int piv=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                piv=i;
                break;
            }
        }
        if(piv==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        // 2 find the right most index which is greater than pivot index
         for(int i=n-1;i>piv;i--){
            if(nums[i]>nums[piv]){
                swap(nums[i],nums[piv]);
                break;
            }
         }
         // 3 revese the element from pivot
         int i=piv+1;
         int j=n-1;
         while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
         }
    }
};
int main(){
    solution s;
    vector<int>nums={1,2,3};
    s.nextpermutation(nums);
    for(auto num:nums){
        cout<<num<<" ";
    }
    return 0;
}

