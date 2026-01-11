/*
Problem: Next Permutation
Description: Find the next lexicographically greater permutation of a given sequence.
             If no such permutation exists, rearrange to the lowest possible order.

Approach: 1. Find the largest index i such that nums[i] < nums[i+1]
          2. Find the largest index j > i such that nums[i] < nums[j]
          3. Swap nums[i] and nums[j]
          4. Reverse the subarray from i+1 to end
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Find first decreasing element from right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Find element just larger than nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        // Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);
    
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) - in-place modification
*/
