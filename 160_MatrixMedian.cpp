/*
Problem: Matrix Median
Description: Find median of a row-wise sorted matrix.

Approach: Binary search on answer. Count elements <= mid in each row. Median has more than half elements <= it.
*/

#include <bits/stdc++.h>
using namespace std;

int countSmallerEqual(vector<int>& row, int target) {
    return upper_bound(row.begin(), row.end(), target) - row.begin();
}

int matrixMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < rows; i++) {
        minVal = min(minVal, matrix[i][0]);
        maxVal = max(maxVal, matrix[i][cols - 1]);
    }
    
    int desired = (rows * cols + 1) / 2;
    
    while (minVal < maxVal) {
        int mid = minVal + (maxVal - minVal) / 2;
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            count += countSmallerEqual(matrix[i], mid);
        }
        
        if (count < desired) {
            minVal = mid + 1;
        } else {
            maxVal = mid;
        }
    }
    
    return minVal;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    
    cout << "Median: " << matrixMedian(matrix) << endl;
    // Output: 5
    
    return 0;
}

/*
Time Complexity: O(rows * log(cols) * log(max-min))
Space Complexity: O(1)
*/
