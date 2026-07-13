#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    int maxprofit(vector<int>&prices){
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[j]>prices[i]){
                    profit=max(profit,prices[j]-prices[i]);
                }
            }
        }
        return profit;
    }

};
int main(){
    solution s;
    vector<int>prices={7,1,5,3,6,4};
    int ans=s.maxprofit(prices);
    cout<<ans;
    return 0;
}