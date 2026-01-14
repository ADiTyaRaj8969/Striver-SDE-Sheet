"""
Problem: Sliding Window Maximum
Description: Find maximum element in each window of size k in array.

Approach: Use deque to maintain indices of useful elements in decreasing order of values.
"""

from typing import List
from collections import deque

def maxSlidingWindow(nums: List[int], k: int) -> List[int]:
    dq = deque()
    result = []
    
    for i, num in enumerate(nums):
        # Remove elements outside window
        while dq and dq[0] <= i - k:
            dq.popleft()
        
        # Remove smaller elements
        while dq and nums[dq[-1]] < num:
            dq.pop()
        
        dq.append(i)
        
        if i >= k - 1:
            result.append(nums[dq[0]])
    
    return result

def main():
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3
    
    result = maxSlidingWindow(nums, k)
    
    print(f"Sliding window maximums: {result}")
    # Output: [3, 3, 5, 5, 6, 7]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(k)
"""
