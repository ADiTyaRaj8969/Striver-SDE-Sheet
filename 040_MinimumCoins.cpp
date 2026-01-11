/*
Problem: Minimum Coins (Coin Change - Greedy)
Description: Find the minimum number of coins to make a given amount of change.
             For standard denominations, greedy works.

Approach: Start with largest denomination, use as many as possible.
          Move to next smaller denomination.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCoins(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        
        int count = 0;
        
        for (int coin : coins) {
            if (amount == 0) break;
            
            int numCoins = amount / coin;
            count += numCoins;
            amount -= numCoins * coin;
        }
        
        return (amount == 0) ? count : -1;
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int amount = 93;
    
    cout << "Minimum Coins: " << sol.minCoins(coins, amount) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is number of coin denominations
Space Complexity: O(1)
Note: Greedy works for standard denominations only
*/
