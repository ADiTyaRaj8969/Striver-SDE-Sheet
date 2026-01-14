/*
Problem: Single Element in Sorted Array
Description: Find element that appears once in sorted array where every other element appears twice.

Approach: Use binary search. Check if mid is at even/odd index and compare with neighbors.
*/

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n-1] != nums[n-2]) return nums[n-1];
    
    int low = 1, high = n - 2;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
            return nums[mid];
        }
        
        // Check which side single element is
        if ((mid % 2 == 0 && nums[mid] == nums[mid+1]) ||
            (mid % 2 == 1 && nums[mid] == nums[mid-1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    
    cout << "Single element: " << singleNonDuplicate(nums) << endl;
    // Output: 2
    
    return 0;
}

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
