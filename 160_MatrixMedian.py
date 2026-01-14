"""
Problem: Matrix Median
Description: Find median of a row-wise sorted matrix.

Approach: Binary search on answer. Count elements <= mid in each row. Median has more than half elements <= it.
"""

from typing import List
import bisect

def countSmallerEqual(row: List[int], target: int) -> int:
    return bisect.bisect_right(row, target)

def matrixMedian(matrix: List[List[int]]) -> int:
    rows = len(matrix)
    cols = len(matrix[0])
    
    minVal = min(row[0] for row in matrix)
    maxVal = max(row[-1] for row in matrix)
    
    desired = (rows * cols + 1) // 2
    
    while minVal < maxVal:
        mid = (minVal + maxVal) // 2
        count = 0
        
        for row in matrix:
            count += countSmallerEqual(row, mid)
        
        if count < desired:
            minVal = mid + 1
        else:
            maxVal = mid
    
    return minVal

def main():
    matrix = [
        [1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]
    ]
    
    print(f"Median: {matrixMedian(matrix)}")
    # Output: 5

if __name__ == "__main__":
    main()

"""
Time Complexity: O(rows * log(cols) * log(max-min))
Space Complexity: O(1)
"""
