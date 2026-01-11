/*
Problem: Inversion of Array (Count Inversions)
Description: Count pairs (i, j) such that i < j and arr[i] > arr[j].

Approach: Use modified merge sort to count inversions while sorting.
          During merge, count inversions when element from right is smaller.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;
        long long invCount = 0;
        
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                invCount += (mid - i + 1);
            }
        }
        
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        
        for (int i = left, k = 0; i <= right; i++, k++) {
            arr[i] = temp[k];
        }
        
        return invCount;
    }
    
    long long mergeSortAndCount(vector<int>& arr, int left, int right) {
        long long invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            invCount += mergeSortAndCount(arr, left, mid);
            invCount += mergeSortAndCount(arr, mid + 1, right);
            invCount += mergeAndCount(arr, left, mid, right);
        }
        return invCount;
    }
    
public:
    long long inversionCount(vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << "Inversion Count: " << sol.inversionCount(arr) << endl;
    
    return 0;
}

/*
Time Complexity: O(n log n) where n is the length of the array
Space Complexity: O(n) for temporary array during merge
*/
