"""
Problem: LFU Cache
Description: Design and implement Least Frequently Used (LFU) cache.

Approach: Use defaultdict for frequency tracking and OrderedDict for maintaining order.
"""

from collections import defaultdict, OrderedDict

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.min_freq = 0
        self.key_node = {}
        self.freq_list = defaultdict(OrderedDict)
    
    def get(self, key: int) -> int:
        if key not in self.key_node:
            return -1
        value, freq = self.key_node[key]
        self.update_freq(key, value, freq)
        return value
    
    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        
        if key in self.key_node:
            _, freq = self.key_node[key]
            self.update_freq(key, value, freq)
        else:
            if len(self.key_node) >= self.capacity:
                evict_key, _ = self.freq_list[self.min_freq].popitem(last=False)
                del self.key_node[evict_key]
            
            self.key_node[key] = (value, 1)
            self.freq_list[1][key] = None
            self.min_freq = 1
    
    def update_freq(self, key: int, value: int, freq: int) -> None:
        del self.freq_list[freq][key]
        if not self.freq_list[freq] and freq == self.min_freq:
            self.min_freq += 1
        
        self.key_node[key] = (value, freq + 1)
        self.freq_list[freq + 1][key] = None

def main():
    cache = LFUCache(2)
    
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))    # returns 1
    cache.put(3, 3)         # evicts key 2
    print(cache.get(2))    # returns -1
    print(cache.get(3))    # returns 3

if __name__ == "__main__":
    main()

"""
Time Complexity: O(1) for both get and put
Space Complexity: O(capacity)
"""
