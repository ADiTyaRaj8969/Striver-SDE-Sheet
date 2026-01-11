"""
Problem: Subarrays with XOR K
Description: Count the number of subarrays having a given bitwise XOR K.

Approach: Use prefix XOR with hash map. If prefixXOR ^ K exists in map,
          we found subarrays with XOR = K.
"""

from typing import List

class Solution:
    def subarraysWithXorK(self, arr: List[int], k: int) -> int:
        xor_map = {0: 1}  # Empty prefix
        xor_val = 0
        count = 0
        
        for num in arr:
            xor_val ^= num
            
            target = xor_val ^ k
            
            if target in xor_map:
                count += xor_map[target]
            
            xor_map[xor_val] = xor_map.get(xor_val, 0) + 1
        
        return count

if __name__ == "__main__":
    sol = Solution()
    arr = [4, 2, 2, 6, 4]
    k = 6
    print(f"Subarrays with XOR {k}: {sol.subarraysWithXorK(arr, k)}")

"""
Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash map
"""
