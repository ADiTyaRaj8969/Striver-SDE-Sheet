/*
Problem: Partition Equal Subset Sum
Description: Determine if array can be partitioned into two subsets with equal sum.

Approach: This is a subset sum problem. Find if there's a subset with sum = total/2.
          Use DP similar to 0-1 knapsack.
*/

#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int num : nums)
        total += num;
    
    if (total % 2 != 0) return false;
    
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    
    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    
    return dp[target];
}

int main() {
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Can partition: " << (canPartition(nums1) ? "true" : "false") << endl;  // Output: true
    
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Can partition: " << (canPartition(nums2) ? "true" : "false") << endl;  // Output: false
    
    return 0;
}

/*
Time Complexity: O(n * sum)
Space Complexity: O(sum)
*/
