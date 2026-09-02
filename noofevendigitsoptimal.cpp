#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class solution{
    public:
int noofevendigits(vector<int>&nums){
    int count=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
       int len=(int) log10(nums[i])+1; // Calculate the number of digits in the number;
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