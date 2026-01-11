"""
Problem: Largest Rectangle in Histogram
Description: Given an array representing heights of bars in a histogram,
             find the largest rectangular area possible.

Approach: Use monotonic increasing stack. For each bar, pop higher bars
          and calculate area with them as height.
"""

from typing import List

def largestRectangleArea(heights: List[int]) -> int:
    stack = []
    max_area = 0
    n = len(heights)
    
    for i in range(n):
        while stack and heights[stack[-1]] > heights[i]:
            h = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, h * width)
        stack.append(i)
    
    while stack:
        h = heights[stack.pop()]
        width = n if not stack else n - stack[-1] - 1
        max_area = max(max_area, h * width)
    
    return max_area

def main():
    heights1 = [2, 1, 5, 6, 2, 3]
    print(largestRectangleArea(heights1))  # Output: 10
    
    heights2 = [2, 4]
    print(largestRectangleArea(heights2))  # Output: 4

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
