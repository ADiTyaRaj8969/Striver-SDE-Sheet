/*
Problem: Largest Rectangle in Histogram
Description: Find area of largest rectangle in histogram.

Approach: Use stack to find next smaller elements on both sides. Area = height * width.
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;
    
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        st.push(i);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    cout << "Largest rectangle area: " << largestRectangleArea(heights) << endl;
    // Output: 10
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
