/*
Problem: Kth Element of Two Sorted Arrays
Description: Find kth element in union of two sorted arrays without merging.

Approach: Binary search on smaller array. Partition arrays such that left half has k elements.
*/

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n1 = arr1.size(), n2 = arr2.size();
    
    if (n1 > n2) return kthElement(arr2, arr1, k);
    
    int low = max(0, k - n2), high = min(k, n1);
    
    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;
        
        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int right1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : arr2[cut2];
        
        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    
    return -1;
}

int main() {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    
    cout << k << "th element: " << kthElement(arr1, arr2, k) << endl;
    // Output: 6
    
    return 0;
}

/*
Time Complexity: O(log(min(n1, n2)))
Space Complexity: O(1)
*/
