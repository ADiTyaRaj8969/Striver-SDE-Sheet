/*
Problem: Distinct Numbers in Window
Description: Find count of distinct elements in every window of size K.

Approach: Use sliding window with hashmap to track element frequencies.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> distinctInWindow(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    vector<int> result;
    
    // First window
    for (int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }
    result.push_back(freq.size());
    
    // Slide window
    for (int i = k; i < arr.size(); i++) {
        // Remove leftmost element
        freq[arr[i-k]]--;
        if (freq[arr[i-k]] == 0) {
            freq.erase(arr[i-k]);
        }
        
        // Add new element
        freq[arr[i]]++;
        
        result.push_back(freq.size());
    }
    
    return result;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    
    vector<int> result = distinctInWindow(arr, k);
    
    cout << "Distinct counts: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;  // Output: 3 4 4 3
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/
