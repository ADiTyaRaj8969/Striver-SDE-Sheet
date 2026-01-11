"""
Problem: Job Sequencing Problem
Description: Find the maximum profit from scheduling jobs with deadlines.

Approach: Sort jobs by profit (descending). Use greedy approach to schedule
          jobs at the latest possible slot before deadline.
"""

from typing import List

class Job:
    def __init__(self, id, deadline, profit):
        self.id = id
        self.deadline = deadline
        self.profit = profit

class Solution:
    def JobScheduling(self, jobs: List[Job], n: int) -> List[int]:
        # Sort jobs by profit in descending order
        jobs.sort(key=lambda x: x.profit, reverse=True)
        
        # Find maximum deadline
        max_deadline = max(job.deadline for job in jobs)
        
        slots = [-1] * (max_deadline + 1)
        count_jobs = 0
        max_profit = 0
        
        for job in jobs:
            # Try to schedule job at latest possible slot
            for j in range(job.deadline, 0, -1):
                if slots[j] == -1:
                    slots[j] = job.id
                    count_jobs += 1
                    max_profit += job.profit
                    break
        
        return [count_jobs, max_profit]

if __name__ == "__main__":
    sol = Solution()
    jobs = [Job(1, 4, 20), Job(2, 1, 10), Job(3, 1, 40), Job(4, 1, 30)]
    n = 4
    
    result = sol.JobScheduling(jobs, n)
    print(f"Jobs: {result[0]}, Max Profit: {result[1]}")

"""
Time Complexity: O(n^2) where n is number of jobs
Space Complexity: O(max_deadline)
"""
