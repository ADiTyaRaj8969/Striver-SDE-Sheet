/*
Problem: Longest Common Subsequence (LCS)
Description: Find the length of the longest common subsequence between two strings.

Approach: DP - dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1].
          If characters match: dp[i][j] = dp[i-1][j-1] + 1
          Else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[m][n];
}

// Space optimized version
int longestCommonSubsequenceOptimized(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1])
                curr[j] = prev[j-1] + 1;
            else
                curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    
    return prev[n];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << "LCS Length: " << longestCommonSubsequence(text1, text2) << endl;  // Output: 3
    
    string text3 = "abc";
    string text4 = "abc";
    cout << "LCS Length: " << longestCommonSubsequence(text3, text4) << endl;  // Output: 3
    
    return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n) or O(n) for optimized version
*/
