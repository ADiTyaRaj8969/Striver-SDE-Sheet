/*
Problem: Median in a Row-wise Sorted Matrix
Description: Find median in row-wise sorted matrix (not necessarily column-wise sorted).

Approach: Binary search on value range. Count elements smaller than mid. Median divides elements in half.
*/

#include <bits/stdc++.h>
using namespace std;

int countSmaller(vector<int>& row, int target) {
    return upper_bound(row.begin(), row.end(), target) - row.begin();
}

int findMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < rows; i++) {
        minVal = min(minVal, matrix[i][0]);
        maxVal = max(maxVal, matrix[i][cols - 1]);
    }
    
    int desired = (rows * cols) / 2;
    
    while (minVal < maxVal) {
        int mid = minVal + (maxVal - minVal) / 2;
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            count += countSmaller(matrix[i], mid);
        }
        
        if (count <= desired) {
            minVal = mid + 1;
        } else {
            maxVal = mid;
        }
    }
    
    return minVal;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 8, 9},
        {4, 11, 14, 19, 20}
    };
    
    cout << "Median: " << findMedian(matrix) << endl;
    // Output: 8
    
    return 0;
}

/*
Time Complexity: O(rows * log(cols) * log(max-min))
Space Complexity: O(1)
*/
