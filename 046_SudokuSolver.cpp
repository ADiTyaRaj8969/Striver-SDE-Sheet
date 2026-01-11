/*
Problem: Sudoku Solver
Description: Write a program to solve a 9×9 Sudoku puzzle.

Approach: Use backtracking. Try digits 1-9 in empty cells, check if valid.
          If valid, recurse; if not, backtrack.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == c) return false;
            
            // Check column
            if (board[i][col] == c) return false;
            
            // Check 3x3 box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            
                            if (solve(board)) return true;
                            
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    Solution sol;
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
    
    sol.solveSudoku(board);
    
    cout << "Solved Sudoku:" << endl;
    for (auto row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(9^(n*n)) worst case
Space Complexity: O(n*n) for recursion stack
*/
