"""
Problem: Search in 2D Matrix
Description: Search for a target value in a matrix where each row is sorted 
             and the first element of each row is greater than the last element of the previous row.

Approach: Treat the 2D matrix as a 1D sorted array and apply binary search.
"""

from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            mid_value = matrix[mid // n][mid % n]
            
            if mid_value == target:
                return True
            elif mid_value < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return False

if __name__ == "__main__":
    sol = Solution()
    matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    target = 3
    print(f"Found: {'Yes' if sol.searchMatrix(matrix, target) else 'No'}")

"""
Time Complexity: O(log(m * n)) where m and n are matrix dimensions
Space Complexity: O(1)
"""
