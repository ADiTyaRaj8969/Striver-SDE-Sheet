/*
Problem: Majority Element II (>n/3 times)
Description: Find all elements that appear more than n/3 times in the array.
             At most 2 elements can appear more than n/3 times.

Approach: Extended Moore's Voting Algorithm with 2 candidates.
          Verify candidates in a second pass.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;
        
        // Find two candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Verify candidates
        vector<int> result;
        count1 = count2 = 0;
        
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        
        int n = nums.size();
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    vector<int> result = sol.majorityElement(nums);
    
    cout << "Majority Elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1)
*/
