"""
Problem: Distinct Numbers in Window
Description: Count distinct numbers in every window of size k.

Approach: Use hashmap with sliding window. Track frequency of elements in current window.
"""

from typing import List
from collections import defaultdict

def countDistinct(nums: List[int], k: int) -> List[int]:
    freq = defaultdict(int)
    result = []
    
    # First window
    for i in range(k):
        freq[nums[i]] += 1
    result.append(len(freq))
    
    # Slide window
    for i in range(k, len(nums)):
        # Add new element
        freq[nums[i]] += 1
        
        # Remove old element
        freq[nums[i - k]] -= 1
        if freq[nums[i - k]] == 0:
            del freq[nums[i - k]]
        
        result.append(len(freq))
    
    return result

def main():
    nums = [1, 2, 1, 3, 4, 2, 3]
    k = 4
    
    result = countDistinct(nums, k)
    
    print(f"Distinct count in each window: {result}")
    # Output: [3, 4, 4, 3]

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(k)
"""
