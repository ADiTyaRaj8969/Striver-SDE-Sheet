/*
Problem: Longest Increasing Subsequence (LIS)
Description: Find the length of the longest strictly increasing subsequence.

Approach 1: DP - dp[i] = length of LIS ending at index i. O(n^2)
Approach 2: Binary Search - Maintain array of smallest tail elements. O(n log n)
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: DP - O(n^2)
int lengthOfLIS_DP(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<int> dp(n, 1);
    int maxLen = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    
    return maxLen;
}

// Approach 2: Binary Search - O(n log n)
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        
        if (it == tails.end())
            tails.push_back(num);
        else
            *it = num;
    }
    
    return tails.size();
}

int main() {
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS (DP): " << lengthOfLIS_DP(nums1) << endl;  // Output: 4
    cout << "Length of LIS (Binary Search): " << lengthOfLIS(nums1) << endl;  // Output: 4
    
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Length of LIS: " << lengthOfLIS(nums2) << endl;  // Output: 4
    
    return 0;
}

/*
Time Complexity: O(n log n) for binary search approach
Space Complexity: O(n)
*/
