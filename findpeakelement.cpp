#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int findpeakelement(vector<int>&nums){
    int n=nums.size();
    int st=0;
    int end=n-1;
    while(st<end){
        int mid=st+(end-st)/2;
        if(nums[mid]<nums[mid+1]){
            st=mid+1;  // peak lies on right side
        }
        else{
            end=mid;  //// peak lies on left side (including mid)
        }
    }
    return st;  // or end, both converge to peak index
}
};
int main() {
    solution s;
    vector<int> arr = {3,5,7,9,6,1};
    cout << s.findpeakelement(arr); // Output: 3 (value = 9)
    return 0;
}