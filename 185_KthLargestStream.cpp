/*
Problem: K-th Largest Element in Stream
Description: Design class to find kth largest element in stream.

Approach: Use min heap of size k. Top element is kth largest.
*/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kl(3, nums);
    
    cout << kl.add(3) << endl;   // Output: 4
    cout << kl.add(5) << endl;   // Output: 5
    cout << kl.add(10) << endl;  // Output: 5
    cout << kl.add(9) << endl;   // Output: 8
    cout << kl.add(4) << endl;   // Output: 8
    
    return 0;
}

/*
Time Complexity: add O(log k), constructor O(n log k)
Space Complexity: O(k)
*/
