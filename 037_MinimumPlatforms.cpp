/*
Problem: Minimum Number of Platforms
Description: Find the minimum platforms required for a railway station to avoid delays.

Approach: Sort arrival and departure times separately. Use two pointers to track
          platforms needed at any time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep, int n) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platformsNeeded = 0;
        int maxPlatforms = 0;
        int i = 0, j = 0;
        
        while (i < n) {
            if (arr[i] <= dep[j]) {
                platformsNeeded++;
                i++;
            } else {
                platformsNeeded--;
                j++;
            }
            
            maxPlatforms = max(maxPlatforms, platformsNeeded);
        }
        
        return maxPlatforms;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;
    
    cout << "Minimum Platforms Required: " << sol.findPlatform(arr, dep, n) << endl;
    
    return 0;
}

/*
Time Complexity: O(n log n) due to sorting
Space Complexity: O(1)
*/
