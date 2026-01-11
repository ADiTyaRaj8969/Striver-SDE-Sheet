/*
Problem: Stock Span
Description: Find the span of stock prices. Span is the maximum number
             of consecutive days before current day with price <= current price.

Approach: Use monotonic decreasing stack to track indices of prices.
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
Time Complexity: O(1) amortized per call
Space Complexity: O(n)
*/
