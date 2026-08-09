#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
void transpose(vector<vector<int>>&matrix){
    int n=matrix.size();
    int sum=0;
    for(int i=0;i<n;i++){
        
            sum+=matrix[i][i]; // summing the left diagonal elements
            sum+=matrix[i][n-i-1]; // summing the right diagonal elements
        
    }
    if(n%2!=0){ // if the matrix is of odd size, we need to subtract the middle element as it has been added twice
        sum-=matrix[n/2][n/2];
    }
    cout<<"The sum of the diagonals is: "<<sum<<endl;

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
    return 0;
}