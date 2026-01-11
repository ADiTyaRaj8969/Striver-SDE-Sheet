/*
Problem: Merge Overlapping Intervals
Description: Given a collection of intervals, merge all overlapping intervals.

Approach: 1. Sort intervals by start time
          2. Iterate and merge intervals that overlap
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) {
                // Overlapping intervals, merge them
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // Non-overlapping interval
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = sol.merge(intervals);
    
    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n log n) due to sorting, where n is the number of intervals
Space Complexity: O(n) for the result array
*/
