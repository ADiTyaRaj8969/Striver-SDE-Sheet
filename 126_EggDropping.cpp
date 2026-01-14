/*
Problem: Egg Dropping
Description: Find minimum number of trials needed in worst case to find critical
             floor from which eggs break when dropped.

Approach: DP - dp[eggs][floors] = min trials needed.
          For each floor k, if egg breaks: check floors below
          If egg doesn't break: check floors above
          Take worst case and minimize over all floors.
*/

#include <bits/stdc++.h>
using namespace std;

int eggDrop(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));
    
    // Base cases
    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;  // 0 floors, 0 trials
        dp[i][1] = 1;  // 1 floor, 1 trial
    }
    
    for (int j = 1; j <= floors; j++) {
        dp[1][j] = j;  // 1 egg, need j trials
    }
    
    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;
            
            for (int k = 1; k <= j; k++) {
                // Egg breaks: check k-1 floors below with i-1 eggs
                // Egg doesn't break: check j-k floors above with i eggs
                int worstCase = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                dp[i][j] = min(dp[i][j], worstCase);
            }
        }
    }
    
    return dp[eggs][floors];
}

// Optimized with binary search
int eggDropOptimized(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));
    
    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    
    for (int j = 1; j <= floors; j++) {
        dp[1][j] = j;
    }
    
    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;
            
            int low = 1, high = j;
            while (low <= high) {
                int mid = (low + high) / 2;
                int breakCase = dp[i-1][mid-1];
                int noBreakCase = dp[i][j-mid];
                
                int worstCase = 1 + max(breakCase, noBreakCase);
                dp[i][j] = min(dp[i][j], worstCase);
                
                if (breakCase < noBreakCase)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    
    return dp[eggs][floors];
}

int main() {
    int eggs = 2, floors = 10;
    cout << "Minimum trials: " << eggDrop(eggs, floors) << endl;  // Output: 4
    cout << "Minimum trials (optimized): " << eggDropOptimized(eggs, floors) << endl;
    
    return 0;
}

/*
Time Complexity: O(eggs * floors^2) or O(eggs * floors * log floors) with binary search
Space Complexity: O(eggs * floors)
*/
