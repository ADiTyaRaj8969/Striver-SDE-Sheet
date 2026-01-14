/*
Problem: Activity Selection Problem
Description: Select maximum number of activities that don't overlap given start and end times.

Approach: Sort by finish time. Greedily pick activities with earliest finish that don't conflict.
*/

#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int finish;
    int index;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int activitySelection(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    vector<Activity> activities(n);
    
    for (int i = 0; i < n; i++) {
        activities[i] = {start[i], finish[i], i};
    }
    
    sort(activities.begin(), activities.end(), compare);
    
    int count = 1;
    int lastFinish = activities[0].finish;
    
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            count++;
            lastFinish = activities[i].finish;
        }
    }
    
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    
    cout << "Maximum activities: " << activitySelection(start, finish) << endl;
    // Output: 4
    
    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
