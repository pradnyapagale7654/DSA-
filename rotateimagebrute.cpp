#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
void rotate(vector<vector<int>>&matrix){
    int n=matrix.size();
    vector<vector<int>>ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-i-1]=matrix[i][j];  //rotating the matrix by 90 degrees
        }
    }
    //copying the rotated matrix back to the original matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=ans[i][j];
        }
    }
}
};
int main(){
    solution s;
    int n;
    cout<<"enter the size of the matrix: ";
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    cout<<"enter the elements of the matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    s.rotate(matrix);
    cout<<"the rotated matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}