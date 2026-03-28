#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class solution {
    public:
  vector<int>find(vector<vector<int>>&grid){
    int n=grid.size();
    int repeat=-1;
    int missing=-1;
    unordered_map<int,int>mp;
    //find frequency
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            mp[grid[row][col]]++;
        }
    }
   // check frequency of  1 to n interval elements in map and check whether it is missing or repeated
   for(int i=1;i<=n*n;i++){
    if(mp[i]==2){
        repeat=i;
    }
    if(mp[i]==0){
        missing=i;
    }
   }
    return {repeat,missing};
  }
};
int main(){
    solution s;
    vector<vector<int> >grid={{1,2,5},{4,3,8},{2,6,9}};
    vector<int>result=s.find(grid);
    for(int x:result){
        cout<<x;
    }
    return 0;
}