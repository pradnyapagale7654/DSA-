#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i=0;i<31;i++){
            if(pow(2,i)==n){
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    int n=16;
    bool res=s.isPowerOfTwo(n);
    if(res){
        cout<<n<<" is a power of two."<<endl;
    }
    else{
        cout<<n<<" is not a power of two."<<endl;
    }
    return 0;
}