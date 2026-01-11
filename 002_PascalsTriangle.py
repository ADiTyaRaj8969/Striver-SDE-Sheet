"""
Problem: Pascal's Triangle
Description: Generate the first n rows of Pascal's triangle.
             Each number is the sum of the two numbers directly above it.

Approach: Each row starts and ends with 1. For middle elements, calculate using
          the formula: current[i] = previous[i-1] + previous[i]
"""

from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = []
        
        for i in range(numRows):
            row = [1] * (i + 1)
            
            for j in range(1, i):
                row[j] = result[i - 1][j - 1] + result[i - 1][j]
            
            result.append(row)
        
        return result

if __name__ == "__main__":
    sol = Solution()
    n = 5
    result = sol.generate(n)
    
    for row in result:
        print(row)

"""
Time Complexity: O(n^2) where n is the number of rows
Space Complexity: O(n^2) for storing the triangle
"""
