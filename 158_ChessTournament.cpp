/*
Problem: Chess Tournament
Description: Place C players in N positions such that minimum distance between any two is maximized.

Approach: Binary search on minimum distance. Check if placement is possible with given distance constraint.
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& positions, int players, int minDist) {
    int count = 1;
    int lastPos = positions[0];
    
    for (int i = 1; i < positions.size(); i++) {
        if (positions[i] - lastPos >= minDist) {
            count++;
            lastPos = positions[i];
            if (count == players) return true;
        }
    }
    
    return false;
}

int chessTournament(vector<int>& positions, int players) {
    sort(positions.begin(), positions.end());
    
    int low = 1;
    int high = positions.back() - positions[0];
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlace(positions, players, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;
}

int main() {
    vector<int> positions = {1, 2, 8, 4, 9};
    int players = 3;
    
    cout << "Maximum minimum distance: " << chessTournament(positions, players) << endl;
    // Output: 3
    
    return 0;
}

/*
Time Complexity: O(n log n + n log(max-min))
Space Complexity: O(1)
*/
