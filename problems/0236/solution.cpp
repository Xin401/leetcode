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
  TreeNode* dfsPostOrder(TreeNode* node, TreeNode* p, TreeNode* q) {
    if (node == nullptr) return nullptr;

    TreeNode* left = dfsPostOrder(node->left, p, q);
    TreeNode* right = dfsPostOrder(node->right, p, q);

    if (node->val == p->val || node->val == q->val) {
      return node;
    }
    if (left != nullptr && right != nullptr) {
      return node;
    }
    return left ? left : right;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return dfsPostOrder(root, p, q);
  }
};