"""
Problem: Minimum Window Substring
Description: Find smallest substring of s that contains all characters of t.

Approach: Two pointers with sliding window. Expand right, contract left when valid.
"""

from collections import Counter

def minWindow(s: str, t: str) -> str:
    required = Counter(t)
    window = {}
    
    left = right = 0
    formed = 0
    needed = len(required)
    minLen = float('inf')
    minStart = 0
    
    while right < len(s):
        c = s[right]
        window[c] = window.get(c, 0) + 1
        
        if c in required and window[c] == required[c]:
            formed += 1
        
        while formed == needed and left <= right:
            if right - left + 1 < minLen:
                minLen = right - left + 1
                minStart = left
            
            leftChar = s[left]
            window[leftChar] -= 1
            if leftChar in required and window[leftChar] < required[leftChar]:
                formed -= 1
            left += 1
        
        right += 1
    
    return "" if minLen == float('inf') else s[minStart:minStart + minLen]

def main():
    s = "ADOBECODEBANC"
    t = "ABC"
    
    print(f"Minimum window: {minWindow(s, t)}")
    # Output: BANC

if __name__ == "__main__":
    main()

"""
Time Complexity: O(|s| + |t|)
Space Complexity: O(|s| + |t|)
"""
