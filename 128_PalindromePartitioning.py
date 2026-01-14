"""
Problem: Palindrome Partitioning II
Description: Find minimum cuts needed to partition string such that every
             substring is a palindrome.

Approach: DP - dp[i] = min cuts for s[0..i].
          For each position, try all possible last palindrome substrings.
          Also precompute isPalindrome table.
"""

def minCut(s: str) -> int:
    n = len(s)
    
    # Build palindrome table
    isPalin = [[False] * n for _ in range(n)]
    
    for length in range(1, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            
            if length == 1:
                isPalin[i][j] = True
            elif length == 2:
                isPalin[i][j] = (s[i] == s[j])
            else:
                isPalin[i][j] = (s[i] == s[j] and isPalin[i+1][j-1])
    
    # DP for min cuts
    dp = [0] * n
    
    for i in range(n):
        if isPalin[0][i]:
            dp[i] = 0
        else:
            dp[i] = i  # Max cuts
            for j in range(i):
                if isPalin[j+1][i]:
                    dp[i] = min(dp[i], dp[j] + 1)
    
    return dp[n-1]

def main():
    s1 = "aab"
    print("Minimum cuts:", minCut(s1))  # Output: 1
    
    s2 = "a"
    print("Minimum cuts:", minCut(s2))  # Output: 0
    
    s3 = "ab"
    print("Minimum cuts:", minCut(s3))  # Output: 1

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n^2)
Space Complexity: O(n^2)
"""
