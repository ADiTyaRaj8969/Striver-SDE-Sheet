/*
Problem: Remove Duplicates from Sorted Array
Description: Remove duplicates from a sorted array in-place and return new length.

Approach: Use two pointers - one for unique position, one for scanning.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int uniquePos = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[uniquePos]) {
                uniquePos++;
                nums[uniquePos] = nums[i];
            }
        }
        
        return uniquePos + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int newLength = sol.removeDuplicates(nums);
    
    cout << "New Length: " << newLength << endl;
    cout << "Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
*/
