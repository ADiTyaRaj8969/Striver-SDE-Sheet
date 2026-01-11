/*
Problem: N-Queens
Description: Place N queens on an N×N chessboard so none attack each other.

Approach: Use backtracking. Place queen row by row, check if position is safe
          (no queens in same column, diagonal, or anti-diagonal).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void solve(int row, vector<string>& board, vector<vector<string>>& result, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, result, n);
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, board, result, n);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> result = sol.solveNQueens(n);
    
    cout << "N-Queens Solutions:" << endl;
    for (auto solution : result) {
        for (auto row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(n!) 
Space Complexity: O(n^2) for the board
*/
