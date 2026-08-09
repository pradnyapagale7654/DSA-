#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // For n*m matrix transpose
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Transpose will be m*n
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the matrix: ";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Store the returned transpose
    vector<vector<int>> result = s.transpose(matrix);

    cout << "The transposed matrix is:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}