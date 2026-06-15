/*
 * Time Complexity：O(N)
 * Space Complexity：
 * - DFS: O(H)，H 為樹高
 * - BFS: O(W)，W 為樹的最大寬度
 */

#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeTraversalTemplates {
 public:
  void dfsPreOrder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;

    res.push_back(root->val);       // 先處理自己 (Top-down)
    dfsPreOrder(root->left, res);   // 左
    dfsPreOrder(root->right, res);  // 右
  }

  void dfsInOrder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;

    dfsInOrder(root->left, res);   // 左
    res.push_back(root->val);      // 處理自己 (用於 BST 排序)
    dfsInOrder(root->right, res);  // 右
  }

  void dfsPostOrder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;

    dfsPostOrder(root->left, res);   // 左
    dfsPostOrder(root->right, res);  // 右
    res.push_back(root->val);        // 最後處理自己 (Bottom-up 收集子樹結果)
  }

  vector<vector<int>> bfsLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();  // 1. 鎖定當層的節點數量
      vector<int> level;    // 儲存當層的值

      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();

        level.push_back(node->val);

        // 2. 將下一層的子節點排入佇列
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
      }
      res.push_back(level);
    }
    return res;
  }
};