"""
Problem: Compare Version Numbers
Description: Compare two version numbers version1 and version2.

Approach: Split by dots and compare each level numerically.
"""

def compareVersion(version1: str, version2: str) -> int:
    v1 = list(map(int, version1.split('.')))
    v2 = list(map(int, version2.split('.')))
    
    # Pad shorter version with zeros
    while len(v1) < len(v2):
        v1.append(0)
    while len(v2) < len(v1):
        v2.append(0)
    
    for i in range(len(v1)):
        if v1[i] < v2[i]:
            return -1
        elif v1[i] > v2[i]:
            return 1
    
    return 0

def main():
    print(compareVersion("1.01", "1.001"))  # Output: 0
    print(compareVersion("1.0", "1.0.0"))   # Output: 0
    print(compareVersion("0.1", "1.1"))     # Output: -1

if __name__ == "__main__":
    main()

"""
Time Complexity: O(max(n1, n2))
Space Complexity: O(n1 + n2)
"""
