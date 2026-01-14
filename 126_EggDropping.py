"""
Problem: Egg Dropping
Description: Find minimum number of trials needed in worst case to find critical
             floor from which eggs break when dropped.

Approach: DP - dp[eggs][floors] = min trials needed.
          For each floor k, if egg breaks: check floors below
          If egg doesn't break: check floors above
          Take worst case and minimize over all floors.
"""

def eggDrop(eggs: int, floors: int) -> int:
    dp = [[0] * (floors + 1) for _ in range(eggs + 1)]
    
    # Base cases
    for i in range(1, eggs + 1):
        dp[i][0] = 0  # 0 floors, 0 trials
        dp[i][1] = 1  # 1 floor, 1 trial
    
    for j in range(1, floors + 1):
        dp[1][j] = j  # 1 egg, need j trials
    
    for i in range(2, eggs + 1):
        for j in range(2, floors + 1):
            dp[i][j] = float('inf')
            
            for k in range(1, j + 1):
                # Egg breaks: check k-1 floors below with i-1 eggs
                # Egg doesn't break: check j-k floors above with i eggs
                worstCase = 1 + max(dp[i-1][k-1], dp[i][j-k])
                dp[i][j] = min(dp[i][j], worstCase)
    
    return dp[eggs][floors]

# Optimized with binary search
def eggDropOptimized(eggs: int, floors: int) -> int:
    dp = [[0] * (floors + 1) for _ in range(eggs + 1)]
    
    for i in range(1, eggs + 1):
        dp[i][0] = 0
        dp[i][1] = 1
    
    for j in range(1, floors + 1):
        dp[1][j] = j
    
    for i in range(2, eggs + 1):
        for j in range(2, floors + 1):
            dp[i][j] = float('inf')
            
            low, high = 1, j
            while low <= high:
                mid = (low + high) // 2
                breakCase = dp[i-1][mid-1]
                noBreakCase = dp[i][j-mid]
                
                worstCase = 1 + max(breakCase, noBreakCase)
                dp[i][j] = min(dp[i][j], worstCase)
                
                if breakCase < noBreakCase:
                    low = mid + 1
                else:
                    high = mid - 1
    
    return dp[eggs][floors]

def main():
    eggs, floors = 2, 10
    print("Minimum trials:", eggDrop(eggs, floors))  # Output: 4
    print("Minimum trials (optimized):", eggDropOptimized(eggs, floors))

if __name__ == "__main__":
    main()

"""
Time Complexity: O(eggs * floors^2) or O(eggs * floors * log floors) with binary search
Space Complexity: O(eggs * floors)
"""
