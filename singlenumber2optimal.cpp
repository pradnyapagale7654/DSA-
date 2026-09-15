#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ones = 0;
       int twos=0;
       for(int i = 0; i < nums.size(); i++){
         ones=(ones^nums[i])& ~twos;
         twos=(twos^nums[i]) & ~ones;
       }

       return ones;
    }
};
int main(){
    Solution s;
    vector<int>nums={2,2,3,2};
    int res=s.singleNumber(nums);
    cout<<"The single number is: "<<res<<endl;
    return 0;
}