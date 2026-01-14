"""
Problem: Max of Min of Every Window Size
Description: For every window size, find maximum of minimums in all windows of that size.

Approach: Use stack to find next and previous smaller elements. Calculate window size for each element as minimum.
"""

from typing import List

def maxOfMin(arr: List[int]) -> List[int]:
    n = len(arr)
    left = [0] * n
    right = [0] * n
    stack = []
    
    # Find previous smaller
    for i in range(n):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        left[i] = -1 if not stack else stack[-1]
        stack.append(i)
    
    stack.clear()
    
    # Find next smaller
    for i in range(n - 1, -1, -1):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        right[i] = n if not stack else stack[-1]
        stack.append(i)
    
    result = [0] * (n + 1)
    
    # Fill result
    for i in range(n):
        length = right[i] - left[i] - 1
        result[length] = max(result[length], arr[i])
    
    # Fill remaining positions
    for i in range(n - 1, 0, -1):
        result[i] = max(result[i], result[i + 1])
    
    return result[1:]

def main():
    arr = [10, 20, 30, 50, 10, 70, 30]
    result = maxOfMin(arr)
    
    print(f"Max of min for each window size: {result}")
    # Output: [70, 30, 20, 10, 10, 10, 10]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
