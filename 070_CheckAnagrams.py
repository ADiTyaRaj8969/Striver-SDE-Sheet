"""
Problem: Check for Anagrams
Description: Check if two strings are anagrams of each other.

Approach: Count character frequencies and compare.
"""

from collections import Counter

def isAnagram(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False
    return Counter(s) == Counter(t)

def main():
    print(isAnagram("anagram", "nagaram"))  # Output: True
    print(isAnagram("rat", "car"))          # Output: False

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(1) - at most 26 characters
"""
