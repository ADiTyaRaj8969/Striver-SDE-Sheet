/*
Problem: Rotate Matrix (Rotate Image)
Description: Rotate an N x N 2D matrix by 90 degrees clockwise in-place.

Approach: 1. Transpose the matrix (swap matrix[i][j] with matrix[j][i])
          2. Reverse each row
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix);
    
    for (auto row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(n^2) where n is the dimension of the matrix
Space Complexity: O(1) - in-place rotation
*/
