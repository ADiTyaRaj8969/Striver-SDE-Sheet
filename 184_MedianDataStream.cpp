/*
Problem: Find Median from Data Stream
Description: Design data structure to find median from stream of numbers.

Approach: Use two heaps - max heap for smaller half, min heap for larger half. Balance sizes.
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;  // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // larger half
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl;  // 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;  // 2
    
    return 0;
}

/*
Time Complexity: addNum O(log n), findMedian O(1)
Space Complexity: O(n)
*/
