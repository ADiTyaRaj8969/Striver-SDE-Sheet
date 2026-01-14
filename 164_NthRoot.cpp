/*
Problem: Nth Root of Integer
Description: Find nth root of integer M. Return -1 if root doesn't exist.

Approach: Binary search on range [1, M]. Check if mid^n equals M.
*/

#include <bits/stdc++.h>
using namespace std;

long long power(int base, int exp, int limit) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
        if (result > limit) return limit + 1;
    }
    return result;
}

int nthRoot(int n, int m) {
    int low = 1, high = m;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long val = power(mid, n, m);
        
        if (val == m) {
            return mid;
        } else if (val < m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int n = 3, m = 27;
    cout << n << "th root of " << m << " is: " << nthRoot(n, m) << endl;
    // Output: 3
    
    n = 4, m = 69;
    cout << n << "th root of " << m << " is: " << nthRoot(n, m) << endl;
    // Output: -1
    
    return 0;
}

/*
Time Complexity: O(log m * n)
Space Complexity: O(1)
*/
