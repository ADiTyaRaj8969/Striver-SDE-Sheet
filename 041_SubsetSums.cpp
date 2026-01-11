/*
Problem: Subset Sums
Description: Find the sums of all possible subsets of a given array.

Approach: Use recursion/backtracking. For each element, either include or exclude it.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findSubsetSums(int index, int sum, vector<int>& arr, vector<int>& result) {
        if (index == arr.size()) {
            result.push_back(sum);
            return;
        }
        
        // Include current element
        findSubsetSums(index + 1, sum + arr[index], arr, result);
        
        // Exclude current element
        findSubsetSums(index + 1, sum, arr, result);
    }
    
public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result;
        findSubsetSums(0, 0, arr, result);
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3};
    vector<int> result = sol.subsetSums(arr);
    
    cout << "Subset Sums: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(2^n) where n is the size of array
Space Complexity: O(2^n) for storing all subsets
*/
