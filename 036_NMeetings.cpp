/*
Problem: N Meetings in One Room
Description: Find the maximum number of meetings that can be held in one room.

Approach: Sort meetings by end time. Greedily select meetings that don't overlap.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end, int n) {
        vector<pair<int, int>> meetings;
        
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        
        // Sort by end time
        sort(meetings.begin(), meetings.end());
        
        int count = 1;
        int lastEndTime = meetings[0].first;
        
        for (int i = 1; i < n; i++) {
            if (meetings[i].second > lastEndTime) {
                count++;
                lastEndTime = meetings[i].first;
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int n = 6;
    
    cout << "Maximum Meetings: " << sol.maxMeetings(start, end, n) << endl;
    
    return 0;
}

/*
Time Complexity: O(n log n) due to sorting
Space Complexity: O(n) for storing meetings
*/
