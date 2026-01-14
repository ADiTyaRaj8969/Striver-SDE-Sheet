"""
Problem: Allocate Minimum Pages
Description: Allocate books to students such that maximum pages allocated to a student is minimized.

Approach: Binary search on answer. Check if allocation is possible for given max pages.
"""

from typing import List

def isPossible(books: List[int], students: int, maxPages: int) -> bool:
    count = 1
    pages = 0
    
    for book in books:
        if book > maxPages:
            return False
        
        if pages + book > maxPages:
            count += 1
            pages = book
            if count > students:
                return False
        else:
            pages += book
    
    return True

def allocateBooks(books: List[int], students: int) -> int:
    if students > len(books):
        return -1
    
    low = max(books)
    high = sum(books)
    result = -1
    
    while low <= high:
        mid = (low + high) // 2
        
        if isPossible(books, students, mid):
            result = mid
            high = mid - 1
        else:
            low = mid + 1
    
    return result

def main():
    books = [12, 34, 67, 90]
    students = 2
    
    print(f"Minimum maximum pages: {allocateBooks(books, students)}")
    # Output: 113

if __name__ == "__main__":
    main()

"""
Time Complexity: O(n log(sum-max))
Space Complexity: O(1)
"""
