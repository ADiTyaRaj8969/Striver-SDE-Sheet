/*
Problem: Rod Cutting
Description: Given a rod of length n and prices for different lengths,
             determine maximum value obtainable by cutting the rod.

Approach: DP - dp[i] = max value obtainable for rod of length i.
          For each length i, try all cuts and take maximum.
*/

#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], prices[j-1] + dp[i-j]);
        }
    }
    
    return dp[n];
}

// With cut tracking
pair<int, vector<int>> rodCuttingWithCuts(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);
    vector<int> cuts(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (prices[j-1] + dp[i-j] > dp[i]) {
                dp[i] = prices[j-1] + dp[i-j];
                cuts[i] = j;
            }
        }
    }
    
    // Reconstruct cuts
    vector<int> result;
    int len = n;
    while (len > 0) {
        result.push_back(cuts[len]);
        len -= cuts[len];
    }
    
    return {dp[n], result};
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    
    cout << "Maximum value: " << rodCutting(prices, n) << endl;  // Output: 22
    
    auto [maxVal, cuts] = rodCuttingWithCuts(prices, n);
    cout << "Maximum value: " << maxVal << endl;
    cout << "Cuts: ";
    for (int cut : cuts) {
        cout << cut << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
