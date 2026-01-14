/*
Problem: Topological Sort
Description: Find a linear ordering of vertices in a directed acyclic graph (DAG)
             such that for every directed edge u->v, u comes before v.

Approach: Use DFS and push nodes to stack after visiting all neighbors.
          Alternative: Kahn's algorithm (BFS with indegree).
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    
    st.push(node);
}

vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

// Kahn's Algorithm (BFS approach)
vector<int> topologicalSortBFS(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    vector<int> result = topologicalSort(V, adj);
    
    cout << "DFS Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    result = topologicalSortBFS(V, adj);
    
    cout << "BFS Topological Sort (Kahn's): ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
