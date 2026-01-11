/*
Problem: Max Consecutive Ones
Description: Find the maximum number of consecutive 1s in a binary array.

Approach: Use a counter to track consecutive ones, update max when 0 is encountered.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;
        
        for (int num : nums) {
            if (num == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            } else {
                currentCount = 0;
            }
        }
        
        return maxCount;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << "Max Consecutive Ones: " << sol.findMaxConsecutiveOnes(nums) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
*/
