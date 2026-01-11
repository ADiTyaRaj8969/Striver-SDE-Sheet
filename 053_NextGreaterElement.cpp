/*
Problem: Next Greater Element
Description: Find the next greater element for each element in an array.

Approach: Use stack. Traverse from right to left, maintain stack of potential
          next greater elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop smaller elements
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            
            // Top of stack is next greater element
            if (!st.empty()) {
                result[i] = st.top();
            }
            
            // Push current element
            st.push(nums[i]);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = sol.nextGreaterElements(nums);
    
    cout << "Next Greater Elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the size of array
Space Complexity: O(n) for the stack
*/
