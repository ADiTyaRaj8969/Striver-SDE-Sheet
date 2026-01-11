"""
Problem: Longest Palindromic Substring
Description: Find the longest palindromic substring in a string.

Approach: Expand around center for each position (odd and even length palindromes).
"""

def expandAroundCenter(s: str, left: int, right: int) -> str:
    while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
    return s[left + 1:right]

def longestPalindrome(s: str) -> str:
    if len(s) < 1:
        return ""
    
    longest = ""
    
    for i in range(len(s)):
        # Odd length palindromes
        odd = expandAroundCenter(s, i, i)
        if len(odd) > len(longest):
            longest = odd
        
        # Even length palindromes
        even = expandAroundCenter(s, i, i + 1)
        if len(even) > len(longest):
            longest = even
    
    return longest

def main():
    s1 = "babad"
    print(longestPalindrome(s1))  # Output: "bab" or "aba"
    
    s2 = "cbbd"
    print(longestPalindrome(s2))  # Output: "bb"

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n^2)
Space Complexity: O(1)
"""
