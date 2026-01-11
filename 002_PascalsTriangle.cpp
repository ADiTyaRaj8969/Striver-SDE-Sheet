/*
Problem: Pascal's Triangle
Description: Generate the first n rows of Pascal's triangle.
             Each number is the sum of the two numbers directly above it.

Approach: Each row starts and ends with 1. For middle elements, calculate using
          the formula: current[i] = previous[i-1] + previous[i]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            
            result.push_back(row);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> result = sol.generate(n);
    
    for (auto row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(n^2) where n is the number of rows
Space Complexity: O(n^2) for storing the triangle
*/
