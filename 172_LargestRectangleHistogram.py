"""
Problem: Largest Rectangle in Histogram
Description: Find area of largest rectangle in histogram.

Approach: Use stack to find next smaller elements on both sides. Area = height * width.
"""

from typing import List

def largestRectangleArea(heights: List[int]) -> int:
    stack = []
    maxArea = 0
    heights.append(0)
    
    for i, h in enumerate(heights):
        while stack and h < heights[stack[-1]]:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            maxArea = max(maxArea, height * width)
        
        stack.append(i)
    
    return maxArea

def main():
    heights = [2, 1, 5, 6, 2, 3]
    
    print(f"Largest rectangle area: {largestRectangleArea(heights)}")
    # Output: 10

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
