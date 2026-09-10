#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class solution{
    public:
vector<int>topkfrequent(vector<int>&nums,int k){
    unordered_map<int,int>mp;
    for(int num:nums){
        mp[num]++;
    }
    vector<pair<int,int>>arr;
    for(auto x:mp){
        arr.push_back({x.second,x.first});
    }
    //sort according to the frequency in descending order
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    vector<int>res;
    for(int i=0;i<k;i++){
        res.push_back(arr[i].second);
    }
    return res;
}
};
int main(){
    solution s;
    vector<int>nums={1,1,1,2,2,3};
    int k=2;
    vector<int>res=s.topkfrequent(nums,k);
    cout<<"The top "<<k<<" frequent elements are: ";
    for(int num:res){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}