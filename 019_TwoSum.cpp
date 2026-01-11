/*
Problem: Two Sum
Description: Find two numbers in an array that add up to a target value.

Approach: Use hash map to store complement of each element.
          Check if current element exists in map.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            
            map[nums[i]] = i;
        }
        
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash map
*/
