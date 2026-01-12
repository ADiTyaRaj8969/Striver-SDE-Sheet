"""
Problem: KMP Algorithm (Knuth-Morris-Pratt)
Description: Efficient pattern matching using LPS (Longest Proper Prefix-Suffix) array.

Approach: Build LPS array for pattern, use it to avoid redundant comparisons.
"""

from typing import List

def compute_lps(pattern: str) -> List[int]:
    m = len(pattern)
    lps = [0] * m
    length = 0
    i = 1
    
    while i < m:
        if pattern[i] == pattern[length]:
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

def kmp(text: str, pattern: str) -> List[int]:
    n = len(text)
    m = len(pattern)
    result = []
    
    lps = compute_lps(pattern)
    
    i = 0
    j = 0
    while i < n:
        if pattern[j] == text[i]:
            i += 1
            j += 1
        
        if j == m:
            result.append(i - j)
            j = lps[j - 1]
        elif i < n and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    
    return result

def main():
    text = "AABAACAADAABAABA"
    pattern = "AABA"
    
    result = kmp(text, pattern)
    print("Pattern found at indices:", result)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n + m)
Space Complexity: O(m)
"""
