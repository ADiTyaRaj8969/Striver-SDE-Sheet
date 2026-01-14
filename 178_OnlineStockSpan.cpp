/*
Problem: Online Stock Span
Description: Calculate span of stock's price for current day. Span is max consecutive days with price <= today's price.

Approach: Use stack to store (price, span) pairs. Pop smaller prices and accumulate spans.
*/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st;  // {price, span}
    
public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner spanner;
    
    cout << spanner.next(100) << endl;  // Output: 1
    cout << spanner.next(80) << endl;   // Output: 1
    cout << spanner.next(60) << endl;   // Output: 1
    cout << spanner.next(70) << endl;   // Output: 2
    cout << spanner.next(60) << endl;   // Output: 1
    cout << spanner.next(75) << endl;   // Output: 4
    cout << spanner.next(85) << endl;   // Output: 6
    
    return 0;
}

/*
Time Complexity: O(1) amortized
Space Complexity: O(n)
*/
