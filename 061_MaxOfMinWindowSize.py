"""
Problem: Maximum of Minimum for Every Window Size
Description: Given an array, for each window size from 1 to n, find the
             maximum of minimums of all windows of that size.

Approach: Use stacks to find previous and next smaller elements for each element.
"""

from typing import List

def maxOfMin(arr: List[int], n: int) -> List[int]:
    stack = []
    left = [0] * n
    right = [0] * n
    
    # Find previous smaller element
    for i in range(n):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        left[i] = -1 if not stack else stack[-1]
        stack.append(i)
    
    stack.clear()
    
    # Find next smaller element
    for i in range(n - 1, -1, -1):
        while stack and arr[stack[-1]] >= arr[i]:
            stack.pop()
        right[i] = n if not stack else stack[-1]
        stack.append(i)
    
    result = [0] * (n + 1)
    
    # Fill result array
    for i in range(n):
        length = right[i] - left[i] - 1
        result[length] = max(result[length], arr[i])
    
    # Fill remaining positions
    for i in range(n - 1, 0, -1):
        result[i] = max(result[i], result[i + 1])
    
    return result[1:]

def main():
    arr1 = [10, 20, 30, 50, 10, 70, 30]
    print(maxOfMin(arr1, 7))  # Output: [70, 30, 20, 10, 10, 10, 10]
    
    arr2 = [10, 20, 30]
    print(maxOfMin(arr2, 3))  # Output: [30, 20, 10]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
