/*
Problem: Maximum of Minimum for Every Window Size
Description: Given an array, for each window size from 1 to n, find the
             maximum of minimums of all windows of that size.

Approach: Use stacks to find previous and next smaller elements for each element.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfMin(vector<int>& arr, int n) {
    stack<int> st;
    vector<int> left(n), right(n);
    
    // Find previous smaller element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    
    // Find next smaller element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    vector<int> result(n + 1, 0);
    
    // Fill result array
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        result[len] = max(result[len], arr[i]);
    }
    
    // Fill remaining positions
    for (int i = n - 1; i >= 1; i--) {
        result[i] = max(result[i], result[i + 1]);
    }
    
    vector<int> ans(result.begin() + 1, result.end());
    return ans;
}

int main() {
    vector<int> arr1 = {10, 20, 30, 50, 10, 70, 30};
    vector<int> result1 = maxOfMin(arr1, 7);
    for (int x : result1) cout << x << " ";  // Output: 70 30 20 10 10 10 10
    cout << endl;
    
    vector<int> arr2 = {10, 20, 30};
    vector<int> result2 = maxOfMin(arr2, 3);
    for (int x : result2) cout << x << " ";  // Output: 30 20 10
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
