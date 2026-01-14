"""
Problem: Median in a Row-wise Sorted Matrix
Description: Find median in row-wise sorted matrix (not necessarily column-wise sorted).

Approach: Binary search on value range. Count elements smaller than mid. Median divides elements in half.
"""

from typing import List
import bisect

def countSmaller(row: List[int], target: int) -> int:
    return bisect.bisect_right(row, target)

def findMedian(matrix: List[List[int]]) -> int:
    rows = len(matrix)
    cols = len(matrix[0])
    
    minVal = min(row[0] for row in matrix)
    maxVal = max(row[-1] for row in matrix)
    
    desired = (rows * cols) // 2
    
    while minVal < maxVal:
        mid = (minVal + maxVal) // 2
        count = 0
        
        for row in matrix:
            count += countSmaller(row, mid)
        
        if count <= desired:
            minVal = mid + 1
        else:
            maxVal = mid
    
    return minVal

def main():
    matrix = [
        [1, 5, 7, 9, 11],
        [2, 3, 4, 8, 9],
        [4, 11, 14, 19, 20]
    ]
    
    print(f"Median: {findMedian(matrix)}")
    # Output: 8

if __name__ == "__main__":
    main()

"""
Time Complexity: O(rows * log(cols) * log(max-min))
Space Complexity: O(1)
"""
