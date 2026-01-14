/*
Problem: DFS of Graph
Description: Perform Depth First Search traversal of a graph.

Approach: Use recursion to visit nodes, mark as visited to avoid cycles.
*/

#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> result;
    
    dfsHelper(0, adj, visited, result);
    
    return result;
}

int main() {
    int V = 5;
    vector<int> adj[V];
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    
    vector<int> result = dfsOfGraph(V, adj);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
