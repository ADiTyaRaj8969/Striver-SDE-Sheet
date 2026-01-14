/*
Problem: K Most Frequent Elements
Description: Find k most frequent elements in array.

Approach: Use hashmap for frequencies. Use min heap of size k or bucket sort.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    // Min heap of size k
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    
    for (auto& [num, count] : freq) {
        minHeap.push({count, num});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result;
}

// Bucket sort approach - O(n)
vector<int> topKFrequentBucket(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    int n = nums.size();
    vector<vector<int>> bucket(n + 1);
    
    for (auto& [num, count] : freq) {
        bucket[count].push_back(num);
    }
    
    vector<int> result;
    for (int i = n; i >= 0 && result.size() < k; i--) {
        for (int num : bucket[i]) {
            result.push_back(num);
            if (result.size() == k) break;
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    vector<int> result = topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    // Output: 1 2
    
    return 0;
}

/*
Time Complexity: O(n log k) with heap, O(n) with bucket sort
Space Complexity: O(n)
*/
