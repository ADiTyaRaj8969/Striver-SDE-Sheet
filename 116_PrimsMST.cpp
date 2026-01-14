/*
Problem: Minimum Spanning Tree - Prim's Algorithm
Description: Find a minimum spanning tree (MST) for a weighted undirected graph.
             MST connects all vertices with minimum total edge weight.

Approach: Start from any vertex, greedily add minimum weight edge that connects
          a vertex in MST to a vertex outside MST.
*/

#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<pair<int, int>>>& adj) {
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    int mstWeight = 0;
    pq.push({0, 0});  // {weight, vertex}
    
    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        
        inMST[u] = true;
        mstWeight += weight;
        
        for (auto& [v, w] : adj[u]) {
            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }
    
    return mstWeight;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});
    
    int mstWeight = primMST(V, adj);
    
    cout << "Weight of MST: " << mstWeight << endl;
    
    return 0;
}

/*
Time Complexity: O((V + E) log V)
Space Complexity: O(V)
*/
