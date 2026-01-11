/*
Problem: Subarrays with XOR K
Description: Count the number of subarrays having a given bitwise XOR K.

Approach: Use prefix XOR with hash map. If prefixXOR ^ K exists in map,
          we found subarrays with XOR = K.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int>& arr, int k) {
        unordered_map<int, int> xorMap;
        int xorVal = 0;
        int count = 0;
        
        xorMap[0] = 1;  // Empty prefix
        
        for (int num : arr) {
            xorVal ^= num;
            
            int target = xorVal ^ k;
            
            if (xorMap.find(target) != xorMap.end()) {
                count += xorMap[target];
            }
            
            xorMap[xorVal]++;
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Subarrays with XOR " << k << ": " << sol.subarraysWithXorK(arr, k) << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash map
*/
