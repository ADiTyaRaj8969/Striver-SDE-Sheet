"""
Problem: Longest Consecutive Sequence
Description: Find the length of the longest consecutive elements sequence.

Approach: Use hash set for O(1) lookup. For each element, check if it's 
          the start of a sequence (num-1 not in set), then count consecutive elements.
"""

from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        num_set = set(nums)
        max_length = 0
        
        for num in num_set:
            # Check if it's the start of a sequence
            if num - 1 not in num_set:
                current_num = num
                current_length = 1
                
                while current_num + 1 in num_set:
                    current_num += 1
                    current_length += 1
                
                max_length = max(max_length, current_length)
        
        return max_length

if __name__ == "__main__":
    sol = Solution()
    nums = [100, 4, 200, 1, 3, 2]
    print(f"Longest Consecutive Sequence: {sol.longestConsecutive(nums)}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash set
"""
