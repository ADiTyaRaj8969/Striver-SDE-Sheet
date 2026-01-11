"""
Problem: Sudoku Solver
Description: Write a program to solve a 9×9 Sudoku puzzle.

Approach: Use backtracking. Try digits 1-9 in empty cells, check if valid.
          If valid, recurse; if not, backtrack.
"""

from typing import List

class Solution:
    def isValid(self, board: List[List[str]], row: int, col: int, c: str) -> bool:
        for i in range(9):
            # Check row
            if board[row][i] == c:
                return False
            
            # Check column
            if board[i][col] == c:
                return False
            
            # Check 3x3 box
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
                return False
        
        return True
    
    def solve(self, board: List[List[str]]) -> bool:
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for c in '123456789':
                        if self.isValid(board, i, j, c):
                            board[i][j] = c
                            
                            if self.solve(board):
                                return True
                            
                            board[i][j] = '.'  # backtrack
                    
                    return False
        return True
    
    def solveSudoku(self, board: List[List[str]]) -> None:
        self.solve(board)

if __name__ == "__main__":
    sol = Solution()
    board = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    
    sol.solveSudoku(board)
    
    print("Solved Sudoku:")
    for row in board:
        print(' '.join(row))

"""
Time Complexity: O(9^(n*n)) worst case
Space Complexity: O(n*n) for recursion stack
"""
