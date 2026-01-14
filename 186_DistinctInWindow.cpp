/*
Problem: Distinct Numbers in Window
Description: Count distinct numbers in every window of size k.

Approach: Use hashmap with sliding window. Track frequency of elements in current window.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    vector<int> result;
    
    // First window
    for (int i = 0; i < k; i++) {
        freq[nums[i]]++;
    }
    result.push_back(freq.size());
    
    // Slide window
    for (int i = k; i < nums.size(); i++) {
        // Add new element
        freq[nums[i]]++;
        
        // Remove old element
        freq[nums[i - k]]--;
        if (freq[nums[i - k]] == 0) {
            freq.erase(nums[i - k]);
        }
        
        result.push_back(freq.size());
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    
    vector<int> result = countDistinct(nums, k);
    
    cout << "Distinct count in each window: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Output: 3 4 4 3
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/
