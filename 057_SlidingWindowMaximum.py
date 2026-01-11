"""
Problem: Sliding Window Maximum
Description: Given an array and a window size k, find maximum in each
             sliding window of size k.

Approach: Use deque to maintain indices of potential maximums in decreasing order.
"""

from typing import List
from collections import deque

def maxSlidingWindow(nums: List[int], k: int) -> List[int]:
    dq = deque()
    result = []
    
    for i in range(len(nums)):
        # Remove elements outside current window
        if dq and dq[0] == i - k:
            dq.popleft()
        
        # Remove smaller elements as they won't be maximum
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()
        
        dq.append(i)
        
        # Add to result after first window is complete
        if i >= k - 1:
            result.append(nums[dq[0]])
    
    return result

def main():
    nums1 = [1, 3, -1, -3, 5, 3, 6, 7]
    k1 = 3
    print(maxSlidingWindow(nums1, k1))  # Output: [3, 3, 5, 5, 6, 7]
    
    nums2 = [1]
    k2 = 1
    print(maxSlidingWindow(nums2, k2))  # Output: [1]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(k)
"""
