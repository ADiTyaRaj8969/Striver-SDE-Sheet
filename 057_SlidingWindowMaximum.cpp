/*
Problem: Sliding Window Maximum
Description: Given an array and a window size k, find maximum in each
             sliding window of size k.

Approach: Use deque to maintain indices of potential maximums in decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements as they won't be maximum
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Add to result after first window is complete
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = maxSlidingWindow(nums1, k1);
    for (int x : result1) cout << x << " ";  // Output: 3 3 5 5 6 7
    cout << endl;
    
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = maxSlidingWindow(nums2, k2);
    for (int x : result2) cout << x << " ";  // Output: 1
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(k)
*/
