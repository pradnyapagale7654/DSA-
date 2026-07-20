#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
vector<vector<int>>ans;
void solve(int i,vector<int>&arr,vector<int>&temp,int target){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(i==arr.size()){
        return ;
    }
    if(target<0){
        return;
    }
    //not included
    solve(i+1,arr,temp,target);
    //for included
    temp.push_back(arr[i]);
    solve(i,arr,temp,target-arr[i]);
    temp.pop_back();
}
vector<vector<int>>combinationsum(vector<int>&arr,int target){
    vector<int >temp;
    solve(0,arr,temp,target);
    return ans;
}
};
int main(){
    solution s;
     vector<int> arr = {2,3,6,7};

    vector<vector<int>> res = s.combinationsum(arr, 7);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}