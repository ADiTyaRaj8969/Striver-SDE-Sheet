/*
Problem: Binary Search
Description: Search for a target value in a sorted array using binary search.

Approach: Divide search space in half repeatedly. Compare middle element with target.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    
    cout << "Index: " << sol.search(nums, target) << endl;
    
    return 0;
}

/*
Time Complexity: O(log n) where n is the size of array
Space Complexity: O(1)
*/
