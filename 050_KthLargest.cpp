/*
Problem: Kth Largest Element
Description: Find the k-th largest element in an unsorted array.

Approach: Use min heap of size k. Maintain k largest elements in heap.
          Root is the k-th largest.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
    
    // Alternative: Using quickselect (average O(n))
    int findKthLargestQuickSelect(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    
    cout << "Kth Largest: " << sol.findKthLargest(nums, k) << endl;
    
    return 0;
}

/*
Time Complexity: O(n log k) for heap approach, O(n) average for quickselect
Space Complexity: O(k) for heap
*/
