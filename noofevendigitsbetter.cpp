#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int noofevendigits(vector<int>&nums){
    int count=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
       int len=to_string(nums[i]).size();
       if(len%2==0){
            count++;
        }
    }
    return count;
}
};
int main(){
    solution s;
    vector<int> nums={12,345,2,6,7896};
    int result=s.noofevendigits(nums);
    cout<<"The number of even digits in the array is: "<<result<<endl;
    return 0;
}