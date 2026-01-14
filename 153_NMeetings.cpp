/*
Problem: N Meetings in One Room
Description: Given start and end times of meetings, find max number of meetings that can be held in one room.

Approach: Sort meetings by end time. Greedily select meetings that don't overlap.
*/

#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;
    int end;
    int pos;
};

bool compare(Meeting a, Meeting b) {
    if (a.end == b.end) {
        return a.pos < b.pos;
    }
    return a.end < b.end;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<Meeting> meetings(n);
    
    for (int i = 0; i < n; i++) {
        meetings[i] = {start[i], end[i], i + 1};
    }
    
    sort(meetings.begin(), meetings.end(), compare);
    
    int count = 1;
    int lastEnd = meetings[0].end;
    
    for (int i = 1; i < n; i++) {
        if (meetings[i].start > lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }
    
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    
    cout << "Maximum meetings: " << maxMeetings(start, end) << endl;
    // Output: 4
    
    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
