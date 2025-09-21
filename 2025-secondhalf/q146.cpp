#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    struct Node {
        Node *prev;
        Node *next;
        int key;
        int value;
    };

    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        auto it = kvps.find(key);
        if (it == kvps.end()) return -1;
        // Move elem to tail
        Node *elem = it->second;
        if (elem->next == nullptr) return elem->value;
        else if (elem->prev == nullptr) {
            elem->next->prev = nullptr;
            head = elem->next;
            elem->next = nullptr;
            tail->next = elem;
            elem->prev = tail;
            tail = elem;
        } else {
            elem->prev->next = elem->next;
            elem->next->prev = elem->prev;
            elem->prev = tail;
            elem->next = nullptr;
            tail->next = elem;
            tail = elem;
        }
        return elem->value;
    }
    
    void put(int key, int value) {
        auto it = kvps.find(key);
        if (it != kvps.end()) {
            Node *elem = it->second;
            elem->value = value;
            // Move elem to tail
            if (elem->next == nullptr) return;
            else if (elem->prev == nullptr) {
                elem->next->prev = nullptr;
                head = elem->next;
                elem->next = nullptr;
                tail->next = elem;
                elem->prev = tail;
                tail = elem;
            } else {
                elem->prev->next = elem->next;
                elem->next->prev = elem->prev;
                elem->prev = tail;
                elem->next = nullptr;
                tail->next = elem;
                tail = elem;
            }
        } else {
            if (numElements == capacity) {
                Node *tmp = head;
                if (tmp->next != nullptr) {
                    tmp->next->prev = nullptr;
                }
                if (tail == tmp) tail = nullptr;
                head = tmp->next;
                kvps.erase(tmp->key);
                delete tmp;
            } else { numElements += 1; }
            Node *elem = new Node;
            elem->prev = tail;
            elem->next = nullptr;
            elem->value = value;
            elem->key = key;
            if (tail != nullptr) {
                tail->next = elem;
            }
            tail = elem;
            if (head == nullptr) {
                head = elem;
            }
            kvps[key] = elem;
        }
    }

private:
    Node *head = nullptr;
    Node *tail = nullptr;
    unordered_map<int, Node *> kvps;
    int capacity;
    int numElements = 0;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    // vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    LRUCache* obj = new LRUCache(1);
    obj->put(2, 1);
    int param_1 = obj->get(2);
    obj->put(3, 2);
    int param_2 = obj->get(2);
    int param_4 = obj->get(3);
    // vector<int> ans = s.spiralOrder(matrix);
}
