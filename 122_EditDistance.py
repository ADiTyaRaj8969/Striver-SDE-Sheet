"""
Problem: Edit Distance
Description: Find minimum number of operations (insert, delete, replace) to
             convert word1 to word2.

Approach: DP - dp[i][j] = min operations to convert word1[0..i-1] to word2[0..j-1].
          If chars match: dp[i][j] = dp[i-1][j-1]
          Else: dp[i][j] = 1 + min(insert, delete, replace)
"""

def minDistance(word1: str, word2: str) -> int:
    m, n = len(word1), len(word2)
    
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Base cases
    for i in range(m + 1):
        dp[i][0] = i  # Delete all characters from word1
    
    for j in range(n + 1):
        dp[0][j] = j  # Insert all characters to word1
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i-1] == word2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(
                    dp[i-1][j],     # Delete
                    dp[i][j-1],     # Insert
                    dp[i-1][j-1]    # Replace
                )
    
    return dp[m][n]

def main():
    word1 = "horse"
    word2 = "ros"
    print("Edit Distance:", minDistance(word1, word2))  # Output: 3
    
    word3 = "intention"
    word4 = "execution"
    print("Edit Distance:", minDistance(word3, word4))  # Output: 5

if __name__ == "__main__":
    main()

"""
Time Complexity: O(m * n)
Space Complexity: O(m * n)
"""
