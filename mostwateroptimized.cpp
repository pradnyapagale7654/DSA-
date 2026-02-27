#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    int mostwater(const vector<int>& height){
        int n=height.size();
        int maxwater=0;
        int lp=0;
        int rp=n-1;
        while(lp<rp){
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            int area=w*ht;
            maxwater=max(maxwater,area);
            if(height[lp]<height[rp]){
                lp++;
            }
            else{
                rp--;
            }
        }
        return maxwater;
    }
};
int main(){
    solution s;
    vector<int>height={2,4,6,8,9};
    cout<<s.mostwater(height);
    return 0;
}