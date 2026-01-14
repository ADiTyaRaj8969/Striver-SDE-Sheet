/*
Problem: Sliding Window Maximum
Description: Find maximum element in each window of size k in array.

Approach: Use deque to maintain indices of useful elements in decreasing order of values.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = maxSlidingWindow(nums, k);
    
    cout << "Sliding window maximums: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Output: 3 3 5 5 6 7
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/
