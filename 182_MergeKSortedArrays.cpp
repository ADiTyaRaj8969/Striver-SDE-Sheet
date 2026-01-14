/*
Problem: Merge K Sorted Arrays
Description: Merge k sorted arrays into one sorted array.

Approach: Use min heap with (value, arrayIndex, elementIndex). Extract min and add next element from same array.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>>& arrays) {
    vector<int> result;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
    
    // Add first element of each array
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }
    
    while (!minHeap.empty()) {
        auto [val, arrIdx, eleIdx] = minHeap.top();
        minHeap.pop();
        
        result.push_back(val);
        
        // Add next element from same array
        if (eleIdx + 1 < arrays[arrIdx].size()) {
            minHeap.push({arrays[arrIdx][eleIdx + 1], arrIdx, eleIdx + 1});
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    
    vector<int> result = mergeKArrays(arrays);
    
    cout << "Merged array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Output: 1 2 3 4 5 6 7 8 9
    
    return 0;
}

/*
Time Complexity: O(n log k) where n is total elements
Space Complexity: O(k + n)
*/
