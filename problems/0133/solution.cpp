#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    queue<Node*> q;
    unordered_map<Node*, Node*> mp;
    q.push(node);
    mp[node] = new Node(node->val);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        Node* curr = q.front();
        q.pop();
        for (auto& n : curr->neighbors) {
          if (mp.find(n) == mp.end()) {
            mp[n] = new Node(n->val);
            q.push(n);
          }
          mp[curr]->neighbors.push_back(mp[n]);
        }
      }
    }
    return mp[node];
  }
};