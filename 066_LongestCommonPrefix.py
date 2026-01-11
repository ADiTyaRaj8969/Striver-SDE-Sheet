"""
Problem: Longest Common Prefix
Description: Find the longest common prefix string amongst an array of strings.

Approach: Compare characters at each position across all strings.
"""

from typing import List

def longestCommonPrefix(strs: List[str]) -> str:
    if not strs:
        return ""
    
    prefix = strs[0]
    
    for i in range(1, len(strs)):
        while not strs[i].startswith(prefix):
            prefix = prefix[:-1]
            if not prefix:
                return ""
    
    return prefix

def main():
    strs1 = ["flower", "flow", "flight"]
    print(longestCommonPrefix(strs1))  # Output: "fl"
    
    strs2 = ["dog", "racecar", "car"]
    print(longestCommonPrefix(strs2))  # Output: ""

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n * m) where n is number of strings, m is length of shortest string
Space Complexity: O(1)
"""
