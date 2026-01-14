/*
Problem: Matrix Chain Multiplication
Description: Find minimum number of scalar multiplications needed to multiply
             a chain of matrices.

Approach: DP - dp[i][j] = min operations to multiply matrices from i to j.
          Try all possible split points k and take minimum.
*/

#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size() - 1;  // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // len is chain length
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            
            // Try all split points
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    return dp[0][n-1];
}

// Recursive with memoization
int mcmHelper(vector<int>& dims, int i, int j, vector<vector<int>>& memo) {
    if (i == j) return 0;
    
    if (memo[i][j] != -1) return memo[i][j];
    
    int minCost = INT_MAX;
    
    for (int k = i; k < j; k++) {
        int cost = mcmHelper(dims, i, k, memo) + 
                   mcmHelper(dims, k+1, j, memo) + 
                   dims[i] * dims[k+1] * dims[j+1];
        minCost = min(minCost, cost);
    }
    
    return memo[i][j] = minCost;
}

int matrixChainMultiplicationMemo(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return mcmHelper(dims, 0, n-1, memo);
}

int main() {
    vector<int> dims = {40, 20, 30, 10, 30};
    // Matrices: A1(40x20), A2(20x30), A3(30x10), A4(10x30)
    
    cout << "Minimum multiplications: " << matrixChainMultiplication(dims) << endl;  // Output: 26000
    cout << "Minimum multiplications (Memo): " << matrixChainMultiplicationMemo(dims) << endl;
    
    return 0;
}

/*
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/
