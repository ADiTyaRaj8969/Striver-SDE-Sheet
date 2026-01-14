"""
Problem: Celebrity Problem
Description: In a party of N people, find the celebrity. Celebrity knows no one but everyone knows celebrity.

Approach: Use two pointers or stack. Eliminate non-celebrities. Verify remaining candidate.
"""

from typing import List

def knows(matrix: List[List[int]], a: int, b: int) -> bool:
    return matrix[a][b] == 1

def findCelebrity(matrix: List[List[int]]) -> int:
    n = len(matrix)
    candidate = 0
    
    # Find candidate
    for i in range(1, n):
        if knows(matrix, candidate, i):
            candidate = i
    
    # Verify candidate
    for i in range(n):
        if i != candidate:
            if knows(matrix, candidate, i) or not knows(matrix, i, candidate):
                return -1
    
    return candidate

def main():
    matrix = [
        [0, 1, 0],
        [0, 0, 0],
        [0, 1, 0]
    ]
    
    celebrity = findCelebrity(matrix)
    if celebrity == -1:
        print("No celebrity found")
    else:
        print(f"Celebrity: {celebrity}")
    # Output: Celebrity: 1

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""
