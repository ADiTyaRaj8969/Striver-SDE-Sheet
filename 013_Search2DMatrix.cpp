/*
Problem: Search in 2D Matrix
Description: Search for a target value in a matrix where each row is sorted 
             and the first element of each row is greater than the last element of the previous row.

Approach: Treat the 2D matrix as a 1D sorted array and apply binary search.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / n][mid % n];
            
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << "Found: " << (sol.searchMatrix(matrix, target) ? "Yes" : "No") << endl;
    
    return 0;
}

/*
Time Complexity: O(log(m * n)) where m and n are matrix dimensions
Space Complexity: O(1)
*/
