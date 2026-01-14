/*
Problem: Celebrity Problem
Description: In a party of N people, find the celebrity. Celebrity knows no one but everyone knows celebrity.

Approach: Use two pointers or stack. Eliminate non-celebrities. Verify remaining candidate.
*/

#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>>& matrix, int a, int b) {
    return matrix[a][b] == 1;
}

int findCelebrity(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int candidate = 0;
    
    // Find candidate
    for (int i = 1; i < n; i++) {
        if (knows(matrix, candidate, i)) {
            candidate = i;
        }
    }
    
    // Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(matrix, candidate, i) || !knows(matrix, i, candidate)) {
                return -1;
            }
        }
    }
    
    return candidate;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    
    int celebrity = findCelebrity(matrix);
    if (celebrity == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity: " << celebrity << endl;
    }
    // Output: Celebrity: 1
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
