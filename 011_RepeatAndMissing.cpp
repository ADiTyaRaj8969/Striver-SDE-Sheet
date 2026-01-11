/*
Problem: Repeat and Missing Number
Description: Find the repeating and the missing number in an array from 1 to N.

Approach: Use mathematical formulas:
          Let x = repeating, y = missing
          S - Sn = x - y (sum difference)
          S2 - S2n = x^2 - y^2 (square sum difference)
          From these, derive x and y
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long S = 0, S2 = 0;
        
        for (int i = 0; i < n; i++) {
            S += arr[i];
            S2 += (long long)arr[i] * arr[i];
        }
        
        long long Sn = (n * (n + 1)) / 2;
        long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;
        
        long long diff = S - Sn;           // x - y
        long long sum = (S2 - S2n) / diff; // x + y
        
        int repeating = (diff + sum) / 2;
        int missing = sum - repeating;
        
        return {repeating, missing};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> result = sol.findTwoElement(arr);
    
    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
*/
