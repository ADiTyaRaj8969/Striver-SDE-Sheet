/*
Problem: Minimum Spanning Tree - Kruskal's Algorithm
Description: Find a minimum spanning tree (MST) using union-find.
             Sort edges by weight and add edge if it doesn't form cycle.

Approach: Sort all edges by weight. Use Union-Find to check cycles.
          Add edge to MST if it connects two different components.
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent, rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px == py) return false;
        
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        
        return true;
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    
    UnionFind uf(V);
    int mstWeight = 0;
    int edgeCount = 0;
    
    for (const Edge& e : edges) {
        if (uf.unite(e.u, e.v)) {
            mstWeight += e.weight;
            edgeCount++;
            
            if (edgeCount == V - 1)
                break;
        }
    }
    
    return mstWeight;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7}
    };
    
    int mstWeight = kruskalMST(V, edges);
    
    cout << "Weight of MST: " << mstWeight << endl;
    
    return 0;
}

/*
Time Complexity: O(E log E)
Space Complexity: O(V)
*/
