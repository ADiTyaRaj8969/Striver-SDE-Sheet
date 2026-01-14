/*
Problem: Search in Rotated Sorted Array II (with duplicates)
Description: Search target in rotated sorted array that may contain duplicates.

Approach: Modified binary search. Handle duplicates by shrinking search space when arr[low] == arr[mid] == arr[high].
*/

#include <bits/stdc++.h>
using namespace std;

bool searchRotated(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) return true;
        
        // Handle duplicates
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
        
        // Check which half is sorted
        if (nums[low] <= nums[mid]) {
            // Left half is sorted
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    
    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    
    cout << "Found: " << (searchRotated(nums, target) ? "Yes" : "No") << endl;
    // Output: Yes
    
    return 0;
}

/*
Time Complexity: O(log n) average, O(n) worst case with duplicates
Space Complexity: O(1)
*/
