#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> r(9), c(9), b(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') // empty cell
                    continue;
                int boxidx = (i / 3) * 3 + (j / 3);
                if (r[i].count(board[i][j]) || 
                    c[j].count(board[i][j]) || 
                    b[boxidx].count(board[i][j])) {
                    return false;
                }
                r[i].insert(board[i][j]);
                c[j].insert(board[i][j]);
                b[boxidx].insert(board[i][j]);
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (s.isValidSudoku(board))
        cout << "Valid Sudoku" << endl;
    else
        cout << "Invalid Sudoku" << endl;

    return 0;
}
