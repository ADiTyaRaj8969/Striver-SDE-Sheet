/*
Problem: Detect Cycle in Undirected Graph
Description: Check if an undirected graph contains a cycle.

Approach: Use DFS with parent tracking. Cycle exists if we visit a visited node
          that's not the parent.
*/

#include <bits/stdc++.h>
using namespace std;

bool hasCycleDFS(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    
    return false;
}

bool detectCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int V = 5;
    vector<int> adj[V];
    
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1);
    adj[1].push_back(4);
    
    cout << detectCycle(V, adj) << endl;  // Output: 1 (true)
    
    return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
