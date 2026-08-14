#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class solution{
    public:
int thirdmax(vector<int>&nums){
    vector<int>res;
    int n=nums.size();
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    }
    for(auto s:st){
        res.push_back(s);
    }
    sort(res.begin(),res.end(),greater<int>());
    int m=res.size();
    if(m<3){
        return res[0];
    }
    else{
        return res[2];
    }
}
};
int main(){
    solution s;
    vector<int>nums={1,5,2,8,4,9};
    int ans=s.thirdmax(nums);
    cout<<"third max is:"<<ans;
    return 0;
}