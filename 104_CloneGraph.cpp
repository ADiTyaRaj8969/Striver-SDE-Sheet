/*
Problem: Clone Graph
Description: Create a deep copy of an undirected graph.

Approach: Use DFS/BFS with hash map to track cloned nodes.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node(int _val) {
        val = _val;
    }
};

Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& visited) {
    if (!node) return nullptr;
    
    if (visited.find(node) != visited.end()) {
        return visited[node];
    }
    
    Node* clone = new Node(node->val);
    visited[node] = clone;
    
    for (Node* neighbor : node->neighbors) {
        clone->neighbors.push_back(cloneGraph(neighbor, visited));
    }
    
    return clone;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> visited;
    return cloneGraph(node, visited);
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    
    Node* cloned = cloneGraph(node1);
    cout << "Graph cloned successfully" << endl;
    
    return 0;
}

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
