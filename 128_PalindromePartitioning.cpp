/*
Problem: Palindrome Partitioning II
Description: Find minimum cuts needed to partition string such that every
             substring is a palindrome.

Approach: DP - dp[i] = min cuts for s[0..i].
          For each position, try all possible last palindrome substrings.
          Also precompute isPalindrome table.
*/

#include <bits/stdc++.h>
using namespace std;

int minCut(string s) {
    int n = s.size();
    
    // Build palindrome table
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            if (len == 1)
                isPalin[i][j] = true;
            else if (len == 2)
                isPalin[i][j] = (s[i] == s[j]);
            else
                isPalin[i][j] = (s[i] == s[j] && isPalin[i+1][j-1]);
        }
    }
    
    // DP for min cuts
    vector<int> dp(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (isPalin[0][i]) {
            dp[i] = 0;
        } else {
            dp[i] = i;  // Max cuts
            for (int j = 0; j < i; j++) {
                if (isPalin[j+1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    
    return dp[n-1];
}

int main() {
    string s1 = "aab";
    cout << "Minimum cuts: " << minCut(s1) << endl;  // Output: 1
    
    string s2 = "a";
    cout << "Minimum cuts: " << minCut(s2) << endl;  // Output: 0
    
    string s3 = "ab";
    cout << "Minimum cuts: " << minCut(s3) << endl;  // Output: 1
    
    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/
