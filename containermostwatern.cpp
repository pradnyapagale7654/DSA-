#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    int mostwater(const vector<int>&height){
        int ans=0;
        int n=height.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){ // all posssible containers
                int w=j-i;
                int ht=min(height[i],height[j]);
                int area=w*ht;
                ans=max(ans,area);
            }
        }
        return ans;
    }
};
int main(){
    solution s;
    vector<int>height={2,3,6,8,9};
    int ans=s.mostwater(height);
    cout<<ans;
    return 0;
}