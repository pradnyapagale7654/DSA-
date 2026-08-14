#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
vector<int>intersection(vector<int>&num1,vector<int>&num2){
    int n=num1.size();
    int m=num2.size();
    vector<int>ans;
    vector<bool>vis(m,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(num1[i]==num2[j] && !vis[j]){
                ans.push_back(num1[i]);
                vis[j]=true;
                break;
            }
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