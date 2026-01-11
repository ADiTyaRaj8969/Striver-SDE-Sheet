/*
Problem: Largest Rectangle in Histogram
Description: Given an array representing heights of bars in a histogram,
             find the largest rectangular area possible.

Approach: Use monotonic increasing stack. For each bar, pop higher bars
          and calculate area with them as height.
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        int h = heights[st.top()];
        st.pop();
        int width = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, h * width);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights1) << endl;  // Output: 10
    
    vector<int> heights2 = {2, 4};
    cout << largestRectangleArea(heights2) << endl;  // Output: 4
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
