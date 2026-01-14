/*
Problem: LFU Cache
Description: Implement Least Frequently Used cache with get and put operations.

Approach: Use hashmap for key->node and frequency->list. Track minFreq. Update frequencies on access.
*/

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyValue;  // key -> {value, freq}
    unordered_map<int, list<int>> freqList;       // freq -> list of keys
    unordered_map<int, list<int>::iterator> keyIter; // key -> iterator
    
    void updateFreq(int key) {
        int freq = keyValue[key].second;
        freqList[freq].erase(keyIter[key]);
        
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        
        freq++;
        keyValue[key].second = freq;
        freqList[freq].push_front(key);
        keyIter[key] = freqList[freq].begin();
    }
    
public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    
    int get(int key) {
        if (keyValue.find(key) == keyValue.end()) return -1;
        
        updateFreq(key);
        return keyValue[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyValue.find(key) != keyValue.end()) {
            keyValue[key].first = value;
            updateFreq(key);
            return;
        }
        
        if (keyValue.size() >= capacity) {
            int oldKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyValue.erase(oldKey);
            keyIter.erase(oldKey);
        }
        
        keyValue[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};

int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;  // Output: 1
    cache.put(3, 3);
    cout << cache.get(2) << endl;  // Output: -1 (evicted)
    
    return 0;
}

/*
Time Complexity: O(1) for get and put
Space Complexity: O(capacity)
*/
