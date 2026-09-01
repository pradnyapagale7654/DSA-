#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
 vector<int> findErrorNums(vector<int>& nums){
    int n=nums.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    int duplicate=-1;
    int missing=-1;
    for(int i=0;i<n;i++){
        if(mp[i]==0){
            missing=i;
        }
        if(mp[i]==2){
            duplicate=i;
        }
    }
    return {duplicate,missing};
 }
};
int main(){
    solution s;
    vector<int>nums={1,2,2,4};
    vector<int>result=s.findErrorNums(nums);
    cout<<"Duplicate: "<<result[0]<<endl;
    cout<<"Missing: "<<result[1]<<endl;
    return 0;
}
