#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution {
    public:
  vector<int>find(vector<vector<int>>&grid){
    int n=grid.size();
    int repeat=-1;
    int missing=-1;
    for(int i=1;i<n*n;i++){
        int freq=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==i){
                    freq++;
                }
            }
        }
        if(freq==2){
            repeat=i;
        }
        if(freq==0){
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