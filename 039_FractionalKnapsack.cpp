/*
Problem: Fractional Knapsack
Description: Maximize the value of items in a knapsack with fractional weights allowed.

Approach: Calculate value/weight ratio for each item. Sort by ratio (descending).
          Greedily pick items with highest ratio first.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sort by value/weight ratio in descending order
        sort(arr, arr + n, [](Item a, Item b) {
            double r1 = (double)a.value / a.weight;
            double r2 = (double)b.value / b.weight;
            return r1 > r2;
        });
        
        double totalValue = 0.0;
        int currentWeight = 0;
        
        for (int i = 0; i < n; i++) {
            if (currentWeight + arr[i].weight <= W) {
                // Take full item
                currentWeight += arr[i].weight;
                totalValue += arr[i].value;
            } else {
                // Take fraction of item
                int remaining = W - currentWeight;
                totalValue += arr[i].value * ((double)remaining / arr[i].weight);
                break;
            }
        }
        
        return totalValue;
    }
};

int main() {
    Solution sol;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = 3;
    int W = 50;
    
    cout << "Maximum Value: " << sol.fractionalKnapsack(W, arr, n) << endl;
    
    return 0;
}

/*
Time Complexity: O(n log n) due to sorting
Space Complexity: O(1)
*/
