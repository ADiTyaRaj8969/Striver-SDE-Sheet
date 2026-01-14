/*
Problem: Detect Cycle in Directed Graph
Description: Check if a directed graph contains a cycle.

Approach: Use DFS with recursion stack. Cycle exists if we visit a node that's
          currently in the recursion stack.
*/

#include <bits/stdc++.h>
using namespace std;

bool hasCycleDFS(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, adj, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }
    
    recStack[node] = false;
    return false;
}

bool detectCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, adj, visited, recStack))
                return true;
        }
    }
    
    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    cout << detectCycle(V, adj) << endl;  // Output: 1 (true)
    
    return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
