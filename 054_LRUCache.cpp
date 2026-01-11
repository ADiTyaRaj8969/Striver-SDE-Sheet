/*
Problem: LRU Cache
Description: Design a "Least Recently Used" (LRU) cache with get and put operations.

Approach: Use doubly linked list + hash map. List maintains recency order,
          map provides O(1) access.
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;
    
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }
    
    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addNode(node);
            
            if (cache.size() > capacity) {
                Node* tail = popTail();
                cache.erase(tail->key);
                delete tail;
            }
        }
    }
};

int main() {
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;    // returns 1
    cache.put(3, 3);                  // evicts key 2
    cout << cache.get(2) << endl;    // returns -1
    
    return 0;
}

/*
Time Complexity: O(1) for both get and put
Space Complexity: O(capacity)
*/
