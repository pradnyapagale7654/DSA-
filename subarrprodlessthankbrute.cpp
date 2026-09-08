#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int subarraylessthank(vector<int>&nums,int k){
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        long long prod=1;
        for(int j=i;j<n;j++){
            prod*=nums[j];
            if(prod<k){
                count++;
            }
            else{
                break;
            }
        }
    }
    return count;
}
};
int main(){
    solution s;
    vector<int>nums={10,5,2,6};
    int k=100;
    int res=s.subarraylessthank(nums,k);
    cout<<"The number of subarrays with product less than "<<k<<" is: "<<res<<endl;
    return 0;
}