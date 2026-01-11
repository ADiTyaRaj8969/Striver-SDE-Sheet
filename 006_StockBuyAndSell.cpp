/*
Problem: Stock Buy and Sell (Best Time to Buy and Sell Stock)
Description: Find the maximum profit from buying and selling a stock once.
             You must buy before you sell.

Approach: Track minimum price seen so far and calculate maximum profit at each step.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the number of days
Space Complexity: O(1)
*/
