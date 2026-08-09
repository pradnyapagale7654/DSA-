#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    // ********** for n*n matrix transpose **********
    /// @param matrix 
    void transpose(vector<vector<int>>&matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);  //swapping the elements to get the transpose
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
    s.transpose(matrix);
    cout<<"the transposed matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}