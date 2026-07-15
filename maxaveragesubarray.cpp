#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
double maxavgsubarray(vector<int>&nums,int k){
    int n=nums.size();
    double wsum=0;
    //for first windoe
    for(int i=0;i<k;i++){
        wsum=wsum+nums[i];
    }
    double maxsum=wsum; // initialize the maxsum 
    //slide the window
    for(int i=k;i<n;i++){
        wsum=wsum+nums[i];  // add nem element
        //remove the old element
        wsum=wsum-nums[i-k];
        maxsum=max(maxsum,wsum); // update the maxsum
    }
    return maxsum/k;
}
};
int main(){
    solution s;
    vector<int>nums={1,12,-5,-6,50,3};
    double ans=s.maxavgsubarray(nums,4);
    cout<<"max average of subarray:"<<ans;
    return 0;
}