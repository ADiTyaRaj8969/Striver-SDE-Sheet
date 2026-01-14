/*
Problem: Floyd-Warshall Algorithm
Description: Find shortest paths between all pairs of vertices in a weighted graph.
             Can handle negative edge weights but not negative cycles.

Approach: Dynamic Programming. For each intermediate vertex k, check if path
          through k is shorter than direct path.
*/

#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;
    
    // Consider all vertices as intermediate
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Print the solution
    cout << "Shortest distances between all pairs:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> graph(V, vector<int>(V, INT_MAX));
    
    // Distance from a vertex to itself is 0
    for (int i = 0; i < V; i++)
        graph[i][i] = 0;
    
    graph[0][1] = 5;
    graph[0][3] = 10;
    graph[1][2] = 3;
    graph[2][3] = 1;
    
    floydWarshall(graph);
    
    return 0;
}

/*
Time Complexity: O(V^3)
Space Complexity: O(V^2)
*/
