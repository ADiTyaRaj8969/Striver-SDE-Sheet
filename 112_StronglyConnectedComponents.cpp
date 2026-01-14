/*
Problem: Strongly Connected Components (Kosaraju's Algorithm)
Description: Find all strongly connected components in a directed graph.
             A strongly connected component is a maximal set of vertices where
             every vertex is reachable from every other vertex.

Approach: Kosaraju's Algorithm
          1. Do DFS and store nodes in stack by finish time
          2. Transpose the graph
          3. Do DFS on transposed graph in order of stack
*/

#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, adj, visited, st);
        }
    }
    
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& transpose, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    
    for (int neighbor : transpose[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, transpose, visited, component);
        }
    }
}

vector<vector<int>> findSCCs(int V, vector<vector<int>>& adj) {
    // Step 1: Do DFS and fill stack
    vector<bool> visited(V, false);
    stack<int> st;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }
    
    // Step 2: Create transpose graph
    vector<vector<int>> transpose(V);
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            transpose[neighbor].push_back(i);
        }
    }
    
    // Step 3: Do DFS on transpose in order of stack
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (!visited[node]) {
            vector<int> component;
            dfs2(node, transpose, visited, component);
            sccs.push_back(component);
        }
    }
    
    return sccs;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    
    vector<vector<int>> sccs = findSCCs(V, adj);
    
    cout << "Strongly Connected Components:" << endl;
    for (const auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
