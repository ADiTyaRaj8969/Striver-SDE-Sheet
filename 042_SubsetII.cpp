/*
Problem: Subset II (Unique Subsets)
Description: Find all unique subsets from an array that may contain duplicates.

Approach: Sort array, use backtracking and skip duplicates at same recursion level.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findSubsets(int index, vector<int>& nums, vector<int>& current, 
                     vector<vector<int>>& result) {
        result.push_back(current);
        
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;
            
            current.push_back(nums[i]);
            findSubsets(i + 1, nums, current, result);
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, current, result);
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    
    cout << "Unique Subsets:" << endl;
    for (auto subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(2^n) where n is the size of array
Space Complexity: O(2^n) for storing all subsets
*/
