/*
Problem: Longest Consecutive Sequence
Description: Find the length of the longest consecutive elements sequence.

Approach: Use hash set for O(1) lookup. For each element, check if it's 
          the start of a sequence (num-1 not in set), then count consecutive elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;
        
        for (int num : numSet) {
            // Check if it's the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;
                
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }
                
                maxLength = max(maxLength, currentLength);
            }
        }
        
        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << sol.longestConsecutive(nums) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash set
*/
