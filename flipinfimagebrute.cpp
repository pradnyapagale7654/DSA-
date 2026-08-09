#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        vector<vector<int>>ans(n,vector<int>(n));  //image[i] → entire row
     //image[i][j] → one element   also if vector is not passd like only ans(n) still works
        for(int i=0;i<n;i++){
            reverse(image[i].begin(),image[i].end());  // reverse each row
            ans[i]=image[i];  // after reverse ans store keli
            for(int j=0;j<n;j++){  // invert
                if(image[i][j]==0){
                    ans[i][j]=1;
                }
                else{
                    ans[i][j]=0;
                }
            }
        }
        
        return ans;
    }
};
int main(){
    Solution s;
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    vector<vector<int>>image(n,vector<int>(n));
    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>image[i][j];
        }
    }
    vector<vector<int>>result=s.flipAndInvertImage(image);
    cout<<"The flipped and inverted matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}