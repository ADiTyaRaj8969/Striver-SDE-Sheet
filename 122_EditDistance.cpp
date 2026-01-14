/*
Problem: Edit Distance
Description: Find minimum number of operations (insert, delete, replace) to
             convert word1 to word2.

Approach: DP - dp[i][j] = min operations to convert word1[0..i-1] to word2[0..j-1].
          If chars match: dp[i][j] = dp[i-1][j-1]
          Else: dp[i][j] = 1 + min(insert, delete, replace)
*/

#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Base cases
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;  // Delete all characters from word1
    
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;  // Insert all characters to word1
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],     // Delete
                    dp[i][j-1],     // Insert
                    dp[i-1][j-1]    // Replace
                });
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    cout << "Edit Distance: " << minDistance(word1, word2) << endl;  // Output: 3
    
    string word3 = "intention";
    string word4 = "execution";
    cout << "Edit Distance: " << minDistance(word3, word4) << endl;  // Output: 5
    
    return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
