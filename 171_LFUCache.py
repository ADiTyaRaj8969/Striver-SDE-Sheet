"""
Problem: LFU Cache
Description: Implement Least Frequently Used cache with get and put operations.

Approach: Use hashmap for key->node and frequency->list. Track minFreq. Update frequencies on access.
"""

from collections import defaultdict, OrderedDict

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.minFreq = 0
        self.keyValue = {}  # key -> (value, freq)
        self.freqList = defaultdict(OrderedDict)  # freq -> ordered dict of keys
    
    def _updateFreq(self, key: int) -> None:
        value, freq = self.keyValue[key]
        del self.freqList[freq][key]
        
        if not self.freqList[freq] and self.minFreq == freq:
            self.minFreq += 1
        
        freq += 1
        self.keyValue[key] = (value, freq)
        self.freqList[freq][key] = None
    
    def get(self, key: int) -> int:
        if key not in self.keyValue:
            return -1
        
        self._updateFreq(key)
        return self.keyValue[key][0]
    
    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        
        if key in self.keyValue:
            self.keyValue[key] = (value, self.keyValue[key][1])
            self._updateFreq(key)
            return
        
        if len(self.keyValue) >= self.capacity:
            oldKey, _ = self.freqList[self.minFreq].popitem(last=False)
            del self.keyValue[oldKey]
        
        self.keyValue[key] = (value, 1)
        self.freqList[1][key] = None
        self.minFreq = 1

def main():
    cache = LFUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))  # Output: 1
    cache.put(3, 3)
    print(cache.get(2))  # Output: -1 (evicted)

if __name__ == "__main__":
    main()

"""
Time Complexity: O(1) for get and put
Space Complexity: O(capacity)
"""
