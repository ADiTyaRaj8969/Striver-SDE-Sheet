/*
Problem: Minimum Coins
Description: Find minimum number of coins needed to make a given amount using coins of given denominations.

Approach: Use greedy approach (works for canonical coin systems). Sort denominations descending and pick largest coins.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> minCoins(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    
    vector<int> result;
    
    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            result.push_back(coin);
        }
    }
    
    if (amount > 0) {
        return {};  // Not possible
    }
    
    return result;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int amount = 93;
    
    vector<int> result = minCoins(coins, amount);
    
    cout << "Minimum coins needed: " << result.size() << endl;
    cout << "Coins: ";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;
    // Output: 5 coins (50, 20, 20, 2, 1)
    
    return 0;
}

/*
Time Complexity: O(n log n + amount)
Space Complexity: O(result size)
*/
