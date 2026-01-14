/*
Problem: Max of Min of Every Window Size
Description: For every window size, find maximum of minimums in all windows of that size.

Approach: Use stack to find next and previous smaller elements. Calculate window size for each element as minimum.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfMin(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st;
    
    // Find previous smaller
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    while (!st.empty()) st.pop();
    
    // Find next smaller
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    vector<int> result(n + 1, 0);
    
    // Fill result
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
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> result = maxOfMin(arr);
    
    cout << "Max of min for each window size: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Output: 70 30 20 10 10 10 10
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
