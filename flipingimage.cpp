#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipping(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {

            // Reverse each row
            reverse(matrix[i].begin(), matrix[i].end());

            // Invert each element
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = 1;
                }
                else {
                    matrix[i][j] = 0;
                }
            }
        }

        return matrix;
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

    vector<vector<int>> result = s.flipping(matrix);

    cout << "The flipped and inverted matrix is:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}