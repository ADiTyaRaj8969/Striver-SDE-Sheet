/*
Problem: Reverse Pairs
Description: Count pairs (i, j) such that i < j and arr[i] > 2 * arr[j].

Approach: Use modified merge sort similar to inversion count.
          Count reverse pairs during the merge process.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countPairs(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        return count;
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);
        
        for (int i = left, k = 0; i <= right; i++, k++) {
            nums[i] = temp[k];
        }
    }
    
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += countPairs(nums, left, mid, right);
        merge(nums, left, mid, right);
        
        return count;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Reverse Pairs: " << sol.reversePairs(nums) << endl;
    
    return 0;
}

/*
Time Complexity: O(n log n) where n is the length of the array
Space Complexity: O(n) for temporary array during merge
*/
