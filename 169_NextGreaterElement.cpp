/*
Problem: Next Greater Element
Description: For each element in array, find next greater element to its right.

Approach: Use stack. Traverse from right. Pop smaller elements. Top is next greater.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            result[i] = st.top();
        }
        
        st.push(nums[i]);
    }
    
    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(nums);
    
    cout << "Next greater elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Output: 5 10 10 -1 -1
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
