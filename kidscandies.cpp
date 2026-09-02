#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
vector<bool>kidswithcandies(vector<int>&candies,int extracandies){
    int n=candies.size();
    int maxelement=*max_element(candies.begin(),candies.end());
    vector<bool>ans(n);
    for(int i=0;i<n;i++){
        if(candies[i]+extracandies>=maxelement){
            ans[i]=true;    // or directly push it ans vector
        }
        else{
            ans[i]=false;
        }
    }
    return ans;
}
};
int main(){
    solution s;
    vector<int> candies={2,3,5,1,3};
    int extracandies=3;
    vector<bool> result=s.kidswithcandies(candies,extracandies);
    cout<<"The result of kids with candies is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}