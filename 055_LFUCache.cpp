/*
Problem: LFU Cache
Description: Design and implement Least Frequently Used (LFU) cache.

Approach: Use frequency map + doubly linked lists for each frequency.
          HashMap provides O(1) access to nodes.
*/

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
    };
    
    int capacity, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, pair<Node*, Node*>> freqList;
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addNode(Node* node, int freq) {
        if (freqList.find(freq) == freqList.end()) {
            Node* head = new Node(0, 0);
            Node* tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            freqList[freq] = {head, tail};
        }
        
        Node* head = freqList[freq].first;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void updateFreq(Node* node) {
        int freq = node->freq;
        removeNode(node);
        
        if (freqList[freq].first->next == freqList[freq].second) {
            if (minFreq == freq) minFreq++;
        }
        
        node->freq++;
        addNode(node, node->freq);
    }
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }
        Node* node = keyNode[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
        } else {
            if (keyNode.size() == capacity) {
                Node* tail = freqList[minFreq].second;
                Node* toRemove = tail->prev;
                removeNode(toRemove);
                keyNode.erase(toRemove->key);
                delete toRemove;
            }
            
            Node* node = new Node(key, value);
            keyNode[key] = node;
            minFreq = 1;
            addNode(node, 1);
        }
    }
};

int main() {
    LFUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;    // returns 1
    cache.put(3, 3);                  // evicts key 2
    cout << cache.get(2) << endl;    // returns -1
    cout << cache.get(3) << endl;    // returns 3
    
    return 0;
}

/*
Time Complexity: O(1) for both get and put
Space Complexity: O(capacity)
*/
