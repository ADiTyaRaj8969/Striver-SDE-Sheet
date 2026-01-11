/*
Problem: Sort 0s, 1s, 2s (Dutch National Flag Algorithm)
Description: Sort an array containing only 0s, 1s, and 2s without using sorting algorithms.

Approach: Use three pointers - low, mid, high. 
          Swap elements to place 0s at beginning, 2s at end, and 1s in middle.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) - in-place sorting
*/
