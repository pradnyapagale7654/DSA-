#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n=nums.size();
            int st=0;
            int end=n-1;
            int mid;
            while(st<=end){
                 mid=st+(end-st)/2;
                if(nums[mid]==target){
                    return mid;
                }
                if(nums[st]<=nums[mid]){
                    if(nums[st]<=target && target<=nums[mid]){
                        end=mid-1;
                    }
                    else{
                        st=mid+1;
                    }
                }
                else{
                    if(nums[mid]<=target && target<=nums[end]){
                        st=mid+1;
                    }
                    else{
                        end=mid-1;
                    }
                }
            }
            return -1;
        }
    };
    int main(){
        Solution s;
        vector<int>nums={1,2,3,4,5,8,7,6};
         int target=8;
        cout<<s.search(nums,target);
    }