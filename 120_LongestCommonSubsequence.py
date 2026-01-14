"""
Problem: Longest Common Subsequence (LCS)
Description: Find the length of the longest common subsequence between two strings.

Approach: DP - dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1].
          If characters match: dp[i][j] = dp[i-1][j-1] + 1
          Else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
"""

def longestCommonSubsequence(text1: str, text2: str) -> int:
    m, n = len(text1), len(text2)
    
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[m][n]

# Space optimized version
def longestCommonSubsequenceOptimized(text1: str, text2: str) -> int:
    m, n = len(text1), len(text2)
    
    prev = [0] * (n + 1)
    curr = [0] * (n + 1)
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i-1] == text2[j-1]:
                curr[j] = prev[j-1] + 1
            else:
                curr[j] = max(prev[j], curr[j-1])
        prev = curr[:]
    
    return prev[n]

def main():
    text1 = "abcde"
    text2 = "ace"
    print("LCS Length:", longestCommonSubsequence(text1, text2))  # Output: 3
    
    text3 = "abc"
    text4 = "abc"
    print("LCS Length:", longestCommonSubsequence(text3, text4))  # Output: 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(m * n)
Space Complexity: O(m * n) or O(n) for optimized version
"""
