#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
void rotate(vector<vector<int>>&matrix){
    int n=matrix.size();
    // first find the transpose of the matrix
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);  //swapping the elements to get the transpose
        }
    }
    // then reverse each row of the matrix
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());  //reversing each row to get the rotated matrix
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