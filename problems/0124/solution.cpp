#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
class Solution {
  int dfsPostOrder(TreeNode* root, int& res) {
    if (root == nullptr) return 0;

    int left = dfsPostOrder(root->left, res);
    int right = dfsPostOrder(root->right, res);
    int M = root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0);
    res = max(res, M);
    return max(left, max(right, 0)) + root->val;
  }

 public:
  int maxPathSum(TreeNode* root) {
    if (root == nullptr) return 0;
    int res = root->val;
    dfsPostOrder(root, res);
    return res;
  }
};