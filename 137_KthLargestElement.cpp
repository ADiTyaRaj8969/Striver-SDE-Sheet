/*
Problem: Kth Largest Element in Array
Description: Find the kth largest element in an unsorted array.

Approach 1: Min heap of size k - O(n log k)
Approach 2: Quickselect - O(n) average, O(n^2) worst case
Approach 3: Sort - O(n log n)
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Min Heap
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k)
            minHeap.pop();
    }
    
    return minHeap.top();
}

// Approach 2: Quickselect
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    
    for (int j = left; j < right; j++) {
        if (nums[j] > pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    
    swap(nums[i], nums[right]);
    return i;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right)
        return nums[left];
    
    int pivotIndex = partition(nums, left, right);
    
    if (k == pivotIndex)
        return nums[k];
    else if (k < pivotIndex)
        return quickSelect(nums, left, pivotIndex - 1, k);
    else
        return quickSelect(nums, pivotIndex + 1, right, k);
}

int findKthLargestQuickselect(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k - 1);
}

int main() {
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Kth largest (Heap): " << findKthLargest(nums1, k1) << endl;  // Output: 5
    
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Kth largest (Quickselect): " << findKthLargestQuickselect(nums2, k2) << endl;  // Output: 4
    
    return 0;
}

/*
Time Complexity: O(n log k) for heap, O(n) average for quickselect
Space Complexity: O(k) for heap, O(1) for quickselect
*/
