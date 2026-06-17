/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 private:
  bool dfsPostOrder(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& res) {
    if (node == nullptr) return false;

    bool left = dfsPostOrder(node->left, p, q, res);
    bool right = dfsPostOrder(node->right, p, q, res);
    if (left || right) {
      if ((left && right) || (node->val == p->val || node->val == q->val)) {
        res = node;
      }
      return true;
    }
    if (node->val == p->val || node->val == q->val) {
      return true;
    }
    return false;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* res;
    dfsPostOrder(root, p, q, res);
    return res;
  }
};