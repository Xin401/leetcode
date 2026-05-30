#include <unordered_map>
using namespace std;

struct Node {
  int key;
  int val;
  Node* prev;
  Node* next;
  Node(int key, int val) : key(key), val(val) {}
};

class LRUCache {
  int capacity;
  unordered_map<int, Node*> mp;
  Node* head;
  Node* tail;
  void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  void addNode(Node* node) {
    node->prev = head;
    node->next = head->next;
    head->next = node;
    node->next->prev = node;
  }

 public:
  LRUCache(int capacity) : capacity(capacity) {
    head = new Node(-1, 0);
    tail = new Node(-1, 0);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (mp.count(key)) {
      removeNode(mp[key]);
      addNode(mp[key]);
      return mp[key]->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (get(key) != -1) {
      mp[key]->val = value;
      return;
    }
    Node* cache = new Node(key, value);
    addNode(cache);
    mp[key] = cache;
    if (capacity) {
      capacity--;
    } else {
      int oldest_key = tail->prev->key;
      removeNode(mp[oldest_key]);
      delete mp[oldest_key];
      mp.erase(oldest_key);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */