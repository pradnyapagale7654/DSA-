#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int n=numbers.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(numbers[i]+numbers[j]==target){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>numbers={2,7,11,15};
    int target=9;
    vector<int>res=s.twoSum(numbers,target);
    cout<<"The indices of the two numbers are: "<<res[0]<<" and "<<res[1]<<endl;
    return 0;
}