"""
Problem: Longest Substring Without Repeating Characters
Description: Find the length of the longest substring without repeating characters.

Approach: Use sliding window with hash map to track character positions.
          Adjust window when duplicate found.
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_map = {}
        max_length = 0
        left = 0
        
        for right, char in enumerate(s):
            if char in char_map and char_map[char] >= left:
                left = char_map[char] + 1
            
            char_map[char] = right
            max_length = max(max_length, right - left + 1)
        
        return max_length

if __name__ == "__main__":
    sol = Solution()
    s = "abcabcbb"
    print(f"Longest Substring Without Repeating: {sol.lengthOfLongestSubstring(s)}")

"""
Time Complexity: O(n) where n is the length of the string
Space Complexity: O(min(n, m)) where m is the character set size
"""
