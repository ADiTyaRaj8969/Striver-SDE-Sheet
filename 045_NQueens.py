"""
Problem: N-Queens
Description: Place N queens on an N×N chessboard so none attack each other.

Approach: Use backtracking. Place queen row by row, check if position is safe
          (no queens in same column, diagonal, or anti-diagonal).
"""

from typing import List

class Solution:
    def isSafe(self, row: int, col: int, board: List[List[str]], n: int) -> bool:
        # Check column
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        
        # Check upper left diagonal
        i, j = row - 1, col - 1
        while i >= 0 and j >= 0:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j -= 1
        
        # Check upper right diagonal
        i, j = row - 1, col + 1
        while i >= 0 and j < n:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j += 1
        
        return True
    
    def solve(self, row: int, board: List[List[str]], result: List[List[str]], n: int):
        if row == n:
            result.append([''.join(row) for row in board])
            return
        
        for col in range(n):
            if self.isSafe(row, col, board, n):
                board[row][col] = 'Q'
                self.solve(row + 1, board, result, n)
                board[row][col] = '.'
    
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        board = [['.'] * n for _ in range(n)]
        self.solve(0, board, result, n)
        return result

if __name__ == "__main__":
    sol = Solution()
    n = 4
    result = sol.solveNQueens(n)
    
    print("N-Queens Solutions:")
    for solution in result:
        for row in solution:
            print(row)
        print()

"""
Time Complexity: O(n!)
Space Complexity: O(n^2) for the board
"""
