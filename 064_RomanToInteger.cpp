/*
Problem: Roman to Integer
Description: Convert a Roman numeral string to an integer.

Approach: Iterate through string, subtract if current < next, else add.
*/

#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }
    
    return result;
}

int main() {
    cout << romanToInt("III") << endl;     // Output: 3
    cout << romanToInt("LVIII") << endl;   // Output: 58
    cout << romanToInt("MCMXCIV") << endl; // Output: 1994
    
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
