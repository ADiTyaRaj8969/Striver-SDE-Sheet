/*
Problem: Bellman-Ford Algorithm
Description: Find shortest paths from source to all vertices in weighted graph.
             Can handle negative edge weights and detect negative cycles.

Approach: Relax all edges V-1 times. If we can still relax after V-1 iterations,
          there's a negative cycle.
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

vector<int> bellmanFord(int V, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (const Edge& e : edges) {
            if (dist[e.src] != INT_MAX && dist[e.src] + e.weight < dist[e.dest]) {
                dist[e.dest] = dist[e.src] + e.weight;
            }
        }
    }
    
    // Check for negative cycle
    for (const Edge& e : edges) {
        if (dist[e.src] != INT_MAX && dist[e.src] + e.weight < dist[e.dest]) {
            cout << "Graph contains negative cycle" << endl;
            return {};
        }
    }
    
    return dist;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    
    vector<int> distances = bellmanFord(V, edges, 0);
    
    if (!distances.empty()) {
        cout << "Shortest distances from source 0:" << endl;
        for (int i = 0; i < V; i++) {
            if (distances[i] == INT_MAX)
                cout << i << ": INF" << endl;
            else
                cout << i << ": " << distances[i] << endl;
        }
    }
    
    return 0;
}

/*
Time Complexity: O(V * E)
Space Complexity: O(V)
*/
