#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
vector<int>intersection(vector<int>&num1,vector<int>&num2){
    int n=num1.size();
    int m=num2.size();
    vector<int>ans;
    sort(num1.begin(),num1.end());
    sort(num2.begin(),num2.end());
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(num1[i]==num2[j]){
            ans.push_back(num1[i]);
            i++;
            j++;
        }
        else if(num1[i]<num2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}
};
int main(){
    solution s;
    vector<int>num1={2,5,2,7};
    vector<int>num2={8,7,9,2};
    vector<int>res=s.intersection(num1,num2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}