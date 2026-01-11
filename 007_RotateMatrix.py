"""
Problem: Rotate Matrix (Rotate Image)
Description: Rotate an N x N 2D matrix by 90 degrees clockwise in-place.

Approach: 1. Transpose the matrix (swap matrix[i][j] with matrix[j][i])
          2. Reverse each row
"""

from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        
        # Transpose the matrix
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # Reverse each row
        for i in range(n):
            matrix[i].reverse()

if __name__ == "__main__":
    sol = Solution()
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    sol.rotate(matrix)
    
    for row in matrix:
        print(row)

"""
Time Complexity: O(n^2) where n is the dimension of the matrix
Space Complexity: O(1) - in-place rotation
"""
