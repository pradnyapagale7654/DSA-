#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m=matrix.size();
    int n=matrix[0].size();
    int st=0;
    int end=m*n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        //convert 1 d index to 2d index
        int row=mid/n;
        int col=mid%n;
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]>target){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return false;
}
};
int main(){
    solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int target = 5;

    if (s.searchMatrix(matrix, target)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}