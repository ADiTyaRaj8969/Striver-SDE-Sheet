/*
Problem: Find Peak Element
Description: Find a peak element in array. Peak is element greater than its neighbors.

Approach: Binary search. Compare mid with mid+1. Move towards higher neighbor.
*/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[n-1] > nums[n-2]) return n - 1;
    
    int low = 1, high = n - 2;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            return mid;
        } else if (nums[mid] < nums[mid+1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    
    cout << "Peak element at index: " << findPeakElement(nums) << endl;
    // Output: 2
    
    return 0;
}

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
