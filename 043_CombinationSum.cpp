/*
Problem: Combination Sum
Description: Find all unique combinations in an array that sum to a target.
             Same number may be chosen unlimited times.

Approach: Use backtracking. At each step, either include current element
          (and stay at same index) or move to next element.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findCombinations(int index, int target, vector<int>& candidates,
                         vector<int>& current, vector<vector<int>>& result) {
        if (index == candidates.size()) {
            if (target == 0) {
                result.push_back(current);
            }
            return;
        }
        
        // Include current element (can repeat)
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, current, result);
            current.pop_back();
        }
        
        // Move to next element
        findCombinations(index + 1, target, candidates, current, result);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    
    cout << "Combinations:" << endl;
    for (auto comb : result) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(2^t) where t is the target value
Space Complexity: O(t) for recursion depth
*/
