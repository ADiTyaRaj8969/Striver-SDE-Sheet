/*
Problem: Job Sequencing Problem
Description: Find the maximum profit from scheduling jobs with deadlines.

Approach: Sort jobs by profit (descending). Use greedy approach to schedule
          jobs at the latest possible slot before deadline.
*/

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

class Solution {
public:
    vector<int> JobScheduling(Job arr[], int n) {
        // Sort jobs by profit in descending order
        sort(arr, arr + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });
        
        // Find maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }
        
        vector<int> slots(maxDeadline + 1, -1);
        int countJobs = 0;
        int maxProfit = 0;
        
        for (int i = 0; i < n; i++) {
            // Try to schedule job at latest possible slot
            for (int j = arr[i].deadline; j > 0; j--) {
                if (slots[j] == -1) {
                    slots[j] = arr[i].id;
                    countJobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {countJobs, maxProfit};
    }
};

int main() {
    Solution sol;
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = 4;
    
    vector<int> result = sol.JobScheduling(arr, n);
    cout << "Jobs: " << result[0] << ", Max Profit: " << result[1] << endl;
    
    return 0;
}

/*
Time Complexity: O(n^2) where n is number of jobs
Space Complexity: O(max_deadline)
*/
