/*
Problem: Find Duplicate in Array (Floyd's Cycle Detection)
Description: Find the one duplicate number in an array of N+1 integers from 1 to N.

Approach: Use Floyd's cycle detection algorithm (tortoise and hare).
          Treat array values as pointers to next index.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Find intersection point in the cycle
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Phase 2: Find the entrance to the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate Number: " << sol.findDuplicate(nums) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
*/
