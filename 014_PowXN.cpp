/*
Problem: Power(x, n)
Description: Calculate x raised to the power of n (x^n) efficiently.

Approach: Use binary exponentiation (exponentiation by squaring).
          If n is even: x^n = (x^2)^(n/2)
          If n is odd: x^n = x * x^(n-1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current = x;
        
        while (N > 0) {
            if (N % 2 == 1) {
                result *= current;
            }
            current *= current;
            N /= 2;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    double x = 2.0;
    int n = 10;
    cout << x << "^" << n << " = " << sol.myPow(x, n) << endl;
    
    return 0;
}

/*
Time Complexity: O(log n) where n is the exponent
Space Complexity: O(1)
*/
