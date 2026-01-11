"""
Problem: Rabin Karp Algorithm
Description: Pattern searching using rolling hash function.

Approach: Use polynomial rolling hash with prime modulo to match pattern.
"""

from typing import List

PRIME = 101
MOD = 10**9 + 7

def compute_hash(s: str, length: int) -> int:
    hash_val = 0
    for i in range(length):
        hash_val = (hash_val * PRIME + ord(s[i])) % MOD
    return hash_val

def rabin_karp(text: str, pattern: str) -> List[int]:
    n = len(text)
    m = len(pattern)
    result = []
    
    if m > n:
        return result
    
    pattern_hash = compute_hash(pattern, m)
    text_hash = compute_hash(text, m)
    
    power = pow(PRIME, m - 1, MOD)
    
    for i in range(n - m + 1):
        if pattern_hash == text_hash:
            # Verify match
            if text[i:i + m] == pattern:
                result.append(i)
        
        if i < n - m:
            text_hash = ((text_hash - ord(text[i]) * power) * PRIME + ord(text[i + m])) % MOD
            if text_hash < 0:
                text_hash += MOD
    
    return result

def main():
    text = "AABAACAADAABAABA"
    pattern = "AABA"
    
    result = rabin_karp(text, pattern)
    print("Pattern found at indices:", result)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n + m) average, O(nm) worst case
Space Complexity: O(1)
"""
