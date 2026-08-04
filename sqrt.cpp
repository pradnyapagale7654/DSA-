#include<iostream>
#include<cmath>
using namespace std;    
class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        for(long long  i=1;i*i<=x;i++){
            ans=i;
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