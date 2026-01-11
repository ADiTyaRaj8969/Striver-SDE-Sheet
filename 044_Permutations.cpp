/*
Problem: Permutations
Description: Find all possible permutations of a string or array.

Approach: Use backtracking with swapping. Swap each element with current position
          and recurse for remaining positions.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generatePermutations(int index, vector<int>& nums, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            generatePermutations(index + 1, nums, result);
            swap(nums[index], nums[i]); // backtrack
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generatePermutations(0, nums, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);
    
    cout << "Permutations:" << endl;
    for (auto perm : result) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(n! * n) where n is the size of array
Space Complexity: O(n) for recursion depth
*/
