#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int m=accounts[0].size();
        int richest=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum=sum+accounts[i][j];
            }
            richest=max(sum,richest);
        }
        return richest;
    }
};
int main(){
    Solution s;
    int n,m;
    cout<<"Enter the number of customers: ";
    cin>>n;
    cout<<"Enter the number of banks: ";
    cin>>m;
    vector<vector<int>>accounts(n,vector<int>(m));
    cout<<"Enter the wealth of each customer in each bank: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>accounts[i][j];
        }
    }
    int result=s.maximumWealth(accounts);
    cout<<"The maximum wealth among all customers is: "<<result<<endl;
    return 0;
}