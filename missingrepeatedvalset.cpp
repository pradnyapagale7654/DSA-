#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class solution{
    public:
vector<int>find(vector<vector<int>>&grid){
    int n=grid.size();
    int repeat=-1;
    set<int>s;
    int currsum=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            int num=grid[row][col];
            currsum+=num;
            if(s.count(num)){
                repeat=num;
            }
            s.insert(num);
        }
    }
    int N=n*n;
    int expectedsum=(N*(N+1))/2;
    int missing=expectedsum-(currsum-repeat);
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