/*
Problem: Aggressive Cows
Description: Place C cows in N stalls such that minimum distance between any two cows is maximized.

Approach: Binary search on answer. For each mid distance, check if we can place all cows with min distance >= mid.
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int cows, int minDist) {
    int count = 1;
    int lastPos = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count == cows) return true;
        }
    }
    
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    
    int low = 1;
    int high = stalls.back() - stalls[0];
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlaceCows(stalls, cows, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    
    cout << "Maximum minimum distance: " << aggressiveCows(stalls, cows) << endl;
    // Output: 3
    
    return 0;
}

/*
Time Complexity: O(n log n + n log(max-min))
Space Complexity: O(1)
*/
