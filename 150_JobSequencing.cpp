/*
Problem: Job Sequencing Problem
Description: Given jobs with deadlines and profits, maximize profit by scheduling jobs within deadlines.

Approach: Sort jobs by profit descending. Use greedy approach to place each job in latest available slot.
*/

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);
    
    int maxDeadline = 0;
    for (auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    vector<int> slots(maxDeadline + 1, -1);
    int countJobs = 0, maxProfit = 0;
    
    for (auto& job : jobs) {
        for (int j = job.deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = job.id;
                countJobs++;
                maxProfit += job.profit;
                break;
            }
        }
    }
    
    return {countJobs, maxProfit};
}

int main() {
    vector<Job> jobs = {
        {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}
    };
    
    auto result = jobScheduling(jobs);
    cout << "Jobs scheduled: " << result.first << endl;
    cout << "Max profit: " << result.second << endl;
    // Output: 2 jobs, profit = 60
    
    return 0;
}

/*
Time Complexity: O(n log n + n*m) where m is max deadline
Space Complexity: O(m)
*/
