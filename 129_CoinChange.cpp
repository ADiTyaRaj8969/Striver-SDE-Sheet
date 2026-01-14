/*
Problem: Coin Change
Description: Find minimum number of coins needed to make amount.
             You have infinite supply of each coin denomination.

Approach: DP - dp[i] = min coins needed to make amount i.
          For each amount, try all coin denominations.
*/

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Coin Change II: Count number of ways to make amount
int coinChangeWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[amount];
}

int main() {
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Minimum coins: " << coinChange(coins1, amount1) << endl;  // Output: 3
    cout << "Number of ways: " << coinChangeWays(coins1, amount1) << endl;
    
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Minimum coins: " << coinChange(coins2, amount2) << endl;  // Output: -1
    
    return 0;
}

/*
Time Complexity: O(amount * n)
Space Complexity: O(amount)
*/
