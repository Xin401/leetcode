#include <algorithm>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// struct TreeNode {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode* left, TreeNode* right)
//       : val(x), left(left), right(right) {}
// };
class Solution {
 private:
  bool dfsPostOrder(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& res) {
    if (node == nullptr) return false;

    bool left =
        node->val < p->val ? false : dfsPostOrder(node->left, p, q, res);
    bool right =
        node->val > q->val ? false : dfsPostOrder(node->right, p, q, res);
    if (left || right) {
      if (node == p || node == q || (left && right)) {
        res = node;
      }
      return true;
    } else if (node == p || node == q) {
      return true;
    }
    return false;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* res = nullptr;
    if (p->val > q->val) {
      swap(p, q);
    }
    dfsPostOrder(root, p, q, res);
    return res;
  }
};