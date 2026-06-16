#include <iostream>
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

class Solution {
 private:
  void dfsInOrder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    dfsInOrder(root->left, res);
    res.push_back(root->val);
    dfsInOrder(root->right, res);
  }

 public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    vector<int> res;
    dfsInOrder(root, res);
    for (int i = 0; i < res.size() - 1; i++) {
      if (res[i] >= res[i + 1]) return false;
    }
    return true;
  }
};