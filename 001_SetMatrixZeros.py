"""
Problem: Set Matrix Zeros
Description: Given an m x n matrix, if an element is 0, set its entire row and column to 0.
             Do it in-place without using extra space.

Approach: Use the first row and first column as markers to track which rows and columns 
          need to be set to zero. Use two variables to track if the first row and 
          first column themselves need to be zeroed.
"""

from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        first_row_zero = False
        first_col_zero = False
        
        # Check if first row has any zero
        for j in range(n):
            if matrix[0][j] == 0:
                first_row_zero = True
                break
        
        # Check if first column has any zero
        for i in range(m):
            if matrix[i][0] == 0:
                first_col_zero = True
                break
        
        # Use first row and column as markers
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        
        # Set zeros based on markers (excluding first row and column)
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        # Set first row to zero if needed
        if first_row_zero:
            for j in range(n):
                matrix[0][j] = 0
        
        # Set first column to zero if needed
        if first_col_zero:
            for i in range(m):
                matrix[i][0] = 0

if __name__ == "__main__":
    matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    sol = Solution()
    sol.setZeroes(matrix)
    
    for row in matrix:
        print(row)

"""
Time Complexity: O(m * n) where m is number of rows and n is number of columns
Space Complexity: O(1) - in-place modification using the matrix itself as markers
"""
