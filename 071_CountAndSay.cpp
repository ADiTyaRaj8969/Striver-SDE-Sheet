/*
Problem: Count and Say
Description: Generate the nth term of the count-and-say sequence.

Approach: Iteratively build each term by counting consecutive digits.
*/

#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";
    
    string result = "1";
    
    for (int i = 2; i <= n; i++) {
        string next = "";
        int count = 1;
        
        for (int j = 1; j < result.length(); j++) {
            if (result[j] == result[j - 1]) {
                count++;
            } else {
                next += to_string(count) + result[j - 1];
                count = 1;
            }
        }
        
        next += to_string(count) + result[result.length() - 1];
        result = next;
    }
    
    return result;
}

int main() {
    cout << countAndSay(1) << endl;  // Output: "1"
    cout << countAndSay(4) << endl;  // Output: "1211"
    cout << countAndSay(5) << endl;  // Output: "111221"
    
    return 0;
}

/*
Time Complexity: O(n * m) where m is length of previous term
Space Complexity: O(m)
*/
