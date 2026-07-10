#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    vector<int>generaterow(int n){
        vector<int>ans;
        int val=1;
        ans.push_back(val);
        for(int i=1;i<=n;i++){
            val=val*(n-i+1)/i;  // n=row and i=col
            ans.push_back(val);
        }
        return ans;
    }
vector<vector<int>>generatepascal(int n){
vector<vector<int>>ans;
for(int i=0;i<n;i++){
    ans.push_back(generaterow(i));
}
return ans;

}
};
int main(){
    solution s;
    vector<vector<int>>ans=s.generatepascal(5);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
    return 0;
}