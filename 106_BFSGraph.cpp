/*
Problem: BFS of Graph
Description: Perform Breadth First Search traversal of a graph.

Approach: Use queue for level-order traversal, mark visited nodes.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> result;
    queue<int> q;
    
    q.push(0);
    visited[0] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return result;
}

int main() {
    int V = 5;
    vector<int> adj[V];
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    
    vector<int> result = bfsOfGraph(V, adj);
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
