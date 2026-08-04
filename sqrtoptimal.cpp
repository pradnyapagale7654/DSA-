#include<iostream>
#include<cmath>
using namespace std;    
    class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        int mid;
        int st=0;
        int end=x;
        while(st<=end){
            mid=st+(end-st)/2;
            if((long long) mid*mid<=x){
                // x is large
                ans=mid;
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    int x=8;
    cout<<s.mySqrt(x);
    return 0;
}