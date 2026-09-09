#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class solution{
    public:
int minsizesubarraysum(vector<int>&nums,int target){
    int n=nums.size();
    int minlen=INT_MAX;
    int j;
    for(int i=0;i<n;i++){
        int sum=0;
        for( j=i;j<n;j++){
            sum+=nums[j];
            if(sum>=target){
                minlen=min(minlen,j-i+1);
            }
        }
    }
    if(minlen==INT_MAX){
        return 0;
    }
    return minlen;
}
};
int main(){
    solution s;
    vector<int>nums={2,3,1,2,4,3};
    int target=7;
    int res=s.minsizesubarraysum(nums,target);
    cout<<"The minimum length of a subarray with sum greater than or equal to "<<target<<" is: "<<res<<endl;
    return 0;
}