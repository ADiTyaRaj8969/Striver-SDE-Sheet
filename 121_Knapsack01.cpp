/*
Problem: 0-1 Knapsack
Description: Given weights and values of n items, put items in a knapsack of
             capacity W to get maximum total value. Each item can be taken once.

Approach: DP - dp[i][w] = max value using first i items with capacity w.
          Choice: Include item i or exclude it.
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Don't include item i-1
            dp[i][w] = dp[i-1][w];
            
            // Include item i-1 if possible
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i][w], values[i-1] + dp[i-1][w - weights[i-1]]);
            }
        }
    }
    
    return dp[n][W];
}

// Space optimized version
int knapsackOptimized(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    
    return dp[W];
}

int main() {
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};
    int W = 7;
    
    cout << "Maximum value: " << knapsack(weights, values, W) << endl;  // Output: 9
    cout << "Maximum value (optimized): " << knapsackOptimized(weights, values, W) << endl;
    
    return 0;
}

/*
Time Complexity: O(n * W)
Space Complexity: O(n * W) or O(W) for optimized version
*/
