"""
Problem: Job Sequencing Problem
Description: Given jobs with deadlines and profits, maximize profit by scheduling jobs within deadlines.

Approach: Sort jobs by profit descending. Use greedy approach to place each job in latest available slot.
"""

from typing import List, Tuple

class Job:
    def __init__(self, id: int, deadline: int, profit: int):
        self.id = id
        self.deadline = deadline
        self.profit = profit

def jobScheduling(jobs: List[Job]) -> Tuple[int, int]:
    jobs.sort(key=lambda x: x.profit, reverse=True)
    
    maxDeadline = max(job.deadline for job in jobs)
    
    slots = [-1] * (maxDeadline + 1)
    countJobs = 0
    maxProfit = 0
    
    for job in jobs:
        for j in range(job.deadline, 0, -1):
            if slots[j] == -1:
                slots[j] = job.id
                countJobs += 1
                maxProfit += job.profit
                break
    
    return (countJobs, maxProfit)

def main():
    jobs = [
        Job(1, 4, 20),
        Job(2, 1, 10),
        Job(3, 1, 40),
        Job(4, 1, 30)
    ]
    
    countJobs, maxProfit = jobScheduling(jobs)
    print(f"Jobs scheduled: {countJobs}")
    print(f"Max profit: {maxProfit}")
    # Output: 2 jobs, profit = 60

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log n + n*m) where m is max deadline
Space Complexity: O(m)
"""
