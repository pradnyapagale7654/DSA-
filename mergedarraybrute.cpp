#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
vector<int>mergedarray(vector<int>&num1,int m,vector<int>&num2,int n){
    vector<int>ans;
    //insert all elememts in ans vector of first array
    for(int i=0;i<num1.size();i++){
        ans.push_back(num1[i]);
    }
    //insert all elements in ans vector of 2nd array
    for(int j=0;j<num2.size();j++){
        ans.push_back(num2[j]);
    }
    //sort ans vector
    sort(ans.begin(),ans.end());
    return ans;
}
};
int main(){
    solution s;
    vector<int>num1={1,2,4,5,7};
    vector<int>num2={3,5,8,9};
    int m=5;
    int n=4;
    vector<int>result=s.mergedarray(num1,m,num2,n);
    cout<<"final sorted array:";
    for(int x:result){
        cout<<x;
    }
    return 0;
}