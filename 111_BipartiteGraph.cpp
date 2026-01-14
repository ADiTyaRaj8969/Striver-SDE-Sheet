/*
Problem: Bipartite Graph
Description: Check if a graph is bipartite. A bipartite graph can be colored using
             two colors such that no two adjacent vertices have the same color.

Approach: Use BFS/DFS with coloring. Try to color the graph with two colors.
          If we find adjacent vertices with same color, graph is not bipartite.
*/

#include <bits/stdc++.h>
using namespace std;

bool bfsCheck(int start, vector<vector<int>>& adj, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false;
            }
        }
    }
    
    return true;
}

bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1);
    
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!bfsCheck(i, adj, color))
                return false;
        }
    }
    
    return true;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);
    
    if (isBipartite(V, adj))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;
    
    return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
