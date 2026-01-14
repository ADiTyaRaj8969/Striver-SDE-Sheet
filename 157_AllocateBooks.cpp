/*
Problem: Allocate Minimum Pages
Description: Allocate books to students such that maximum pages allocated to a student is minimized.

Approach: Binary search on answer. Check if allocation is possible for given max pages.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& books, int students, int maxPages) {
    int count = 1;
    int pages = 0;
    
    for (int book : books) {
        if (book > maxPages) return false;
        
        if (pages + book > maxPages) {
            count++;
            pages = book;
            if (count > students) return false;
        } else {
            pages += book;
        }
    }
    
    return true;
}

int allocateBooks(vector<int>& books, int students) {
    if (students > books.size()) return -1;
    
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (isPossible(books, students, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    
    cout << "Minimum maximum pages: " << allocateBooks(books, students) << endl;
    // Output: 113
    
    return 0;
}

/*
Time Complexity: O(n log(sum-max))
Space Complexity: O(1)
*/
