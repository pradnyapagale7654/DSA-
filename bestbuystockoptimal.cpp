#include<iostream>
#include<vector>
#include<algorithm>
#include<algorithm>
using namespace std;
class solution{
    public:
    int maxprofit(vector<int>&prices){
        int profit=0;
        int bestbuy=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]>bestbuy){
                profit=max(profit,prices[i]-bestbuy);
            }
            bestbuy=min(bestbuy,prices[i]);
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