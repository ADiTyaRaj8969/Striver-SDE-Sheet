/*
Problem: Fractional Knapsack
Description: Given weights and values of items, maximize value in knapsack of capacity W. Can take fractions.

Approach: Calculate value/weight ratio for each item. Sort by ratio descending.
          Greedily take items with highest ratio.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    
    double maxValue = 0.0;
    
    for (auto& item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            maxValue += item.value;
        } else {
            maxValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    
    return maxValue;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    
    cout << "Maximum value: " << fractionalKnapsack(W, items) << endl;
    // Output: 240.0
    
    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/
