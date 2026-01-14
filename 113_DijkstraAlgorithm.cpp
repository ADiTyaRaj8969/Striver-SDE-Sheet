/*
Problem: Dijkstra's Algorithm
Description: Find shortest paths from source vertex to all other vertices in a
             weighted graph with non-negative edge weights.

Approach: Use priority queue (min-heap). Greedily pick the unvisited vertex with
          smallest distance, update distances of its neighbors.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});
    
    vector<int> distances = dijkstra(V, adj, 0);
    
    cout << "Shortest distances from source 0:" << endl;
    for (int i = 0; i < V; i++) {
        if (distances[i] == INT_MAX)
            cout << i << ": INF" << endl;
        else
            cout << i << ": " << distances[i] << endl;
    }
    
    return 0;
}

/*
Time Complexity: O((V + E) log V)
Space Complexity: O(V)
*/
