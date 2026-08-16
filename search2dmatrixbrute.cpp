#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();        // rows
        int n = matrix[0].size();     // columns

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution s;

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