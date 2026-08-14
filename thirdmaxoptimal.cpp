#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;
class solution{
    public:
int thirdmax(vector<int>&nums){
    int n=nums.size();
    int first=LONG_MIN;
    int sec=LONG_MIN;
    int third=LONG_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]==first || nums[i]==sec || nums[i]==third){
            continue; // if duplicates then skip
        }
        if(first<nums[i]){
            third=sec;
            sec=first;
            first=nums[i];
        }
        else if(sec<nums[i]){
            third=sec;
            sec=nums[i];
        }
        else if(third<nums[i]){
            third=nums[i];
        }
    }
    if(third==LONG_MIN){
        return first;
    }
    else{
        return third;
    }
}
};
int main(){
    solution s;
    vector<int>nums={1,4,2,8,7,5};
    int ans=s.thirdmax(nums);
    cout<<"third max is:"<<ans;
    return ans;
}