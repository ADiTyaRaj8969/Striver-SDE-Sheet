/*
Problem: Largest Subarray with 0 Sum
Description: Find the length of the largest subarray with a sum of 0.

Approach: Use prefix sum with hash map. If same prefix sum appears twice,
          the subarray between them has sum 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> prefixSumMap;
        int sum = 0;
        int maxLength = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            if (sum == 0) {
                maxLength = i + 1;
            }
            
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[sum]);
            } else {
                prefixSumMap[sum] = i;
            }
        }
        
        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Largest Subarray with 0 Sum: " << sol.maxLen(arr) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash map
*/
