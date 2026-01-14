/*
Problem: Minimum Platforms
Description: Find minimum number of platforms needed for a railway station given arrival and departure times.

Approach: Sort arrival and departure times separately. Use two pointers to track overlapping trains.
*/

#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;
    
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
            maxPlatforms = max(maxPlatforms, platforms);
        } else {
            platforms--;
            j++;
        }
    }
    
    return maxPlatforms;
}

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    
    cout << "Minimum platforms needed: " << findPlatform(arr, dep) << endl;
    // Output: 3
    
    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/
