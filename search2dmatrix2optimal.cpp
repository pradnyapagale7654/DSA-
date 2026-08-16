#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m=matrix.size();
    int n=matrix[0].size();
    int st=0;
    int end=m-1;
    while(st<m-1 && end>=0){
        if(matrix[st][end]==target){
            return true;
        }
        else if(matrix[st][end]>target){
            end--;
        }
        else {
            st++;
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