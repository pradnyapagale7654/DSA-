#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution {
    public:
    vector<int>missingrepeated(vector<int>&nums){
    int n=nums.size();
    vector<int>ans;
    for(int i=1;i<=n;i++){
        int freq=0;
        for(int j=0;j<n;j++){
            if(nums[j]==i){
                freq++;
            }
        }
        if(freq==2){
            ans.push_back(i);
        }
        if(freq==0){
            ans.push_back(i);
        }
    }
    return ans;
    }
};
int main(){
    solution s;
    vector<int> nums={1,2,4,1,5,6};
    vector<int>result=s.missingrepeated(nums);
    for(int x:result){
        cout<<x;
    }
    return 0;
}