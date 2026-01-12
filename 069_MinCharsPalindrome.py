"""
Problem: Minimum Characters to Make String Palindrome
Description: Find minimum characters to be inserted at beginning to make
             string a palindrome.

Approach: Use KMP LPS array on string + reverse string to find longest prefix
          that is also suffix.
"""

from typing import List

def compute_lps(s: str) -> List[int]:
    n = len(s)
    lps = [0] * n
    length = 0
    i = 1
    
    while i < n:
        if s[i] == s[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    
    return lps

def min_chars_to_make_palindrome(s: str) -> int:
    rev = s[::-1]
    concat = s + "$" + rev
    lps = compute_lps(concat)
    return len(s) - lps[-1]

def main():
    s1 = "ABC"
    print(min_chars_to_make_palindrome(s1))  # Output: 2
    
    s2 = "AACECAAAA"
    print(min_chars_to_make_palindrome(s2))  # Output: 2

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""
