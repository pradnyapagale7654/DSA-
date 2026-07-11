#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    vector<vector<int>>merge(vector<vector<int>>&interval){
        int n=interval.size();
        vector<vector<int>>ans;
        sort(interval.begin(),interval.end());
        for(auto inter:interval){
            if(ans.empty() || ans.back()[1]<inter[0]){
                ans.push_back(inter);

            }
            else{
                ans.back()[1]=max(ans.back()[1],inter[1]);
            }
        }
        return ans;

    }
};
int main(){
    
    solution s;
    vector<vector<int>>interval={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans=s.merge(interval);
    for(auto inter:ans){
        cout<<"["<<inter[0]<<","<<inter[1]<<"] ";
    }
    return 0;
}