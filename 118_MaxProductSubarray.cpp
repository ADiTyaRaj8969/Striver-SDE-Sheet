/*
Problem: Maximum Product Subarray
Description: Find the contiguous subarray within an array which has the largest product.

Approach: Keep track of both max and min products ending at current position.
          Min can become max when multiplied by negative number.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(maxProd, minProd);
        
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        
        result = max(result, maxProd);
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Max Product: " << maxProduct(nums1) << endl;  // Output: 6
    
    vector<int> nums2 = {-2, 0, -1};
    cout << "Max Product: " << maxProduct(nums2) << endl;  // Output: 0
    
    vector<int> nums3 = {-2, 3, -4};
    cout << "Max Product: " << maxProduct(nums3) << endl;  // Output: 24
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
