/*
Problem: Merge Sorted Arrays
Description: Merge two sorted arrays into one sorted array without using extra space.
             nums1 has enough space to hold both arrays.

Approach: Fill nums1 from the end using three pointers - for nums1, nums2, and merged position.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Last element in nums1
        int j = n - 1;      // Last element in nums2
        int k = m + n - 1;  // Last position in merged array
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    
    sol.merge(nums1, m, nums2, n);
    
    for (int val : nums1) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(m + n) where m and n are lengths of the two arrays
Space Complexity: O(1) - in-place merging
*/
