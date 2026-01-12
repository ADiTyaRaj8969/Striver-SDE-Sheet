/*
Problem: Compare Version Numbers
Description: Compare two version numbers version1 and version2.

Approach: Split by dots and compare each level numerically.
*/

#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
    int i = 0, j = 0;
    int n1 = version1.length(), n2 = version2.length();
    
    while (i < n1 || j < n2) {
        int num1 = 0, num2 = 0;
        
        while (i < n1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        
        while (j < n2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }
        
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        
        i++;
        j++;
    }
    
    return 0;
}

int main() {
    cout << compareVersion("1.01", "1.001") << endl;  // Output: 0
    cout << compareVersion("1.0", "1.0.0") << endl;   // Output: 0
    cout << compareVersion("0.1", "1.1") << endl;     // Output: -1
    
    return 0;
}

/*
Time Complexity: O(max(n1, n2))
Space Complexity: O(1)
*/
