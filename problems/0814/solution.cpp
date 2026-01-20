/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void cut(TreeNode*&root)
{
    if(root->left)
    {
        cut(root->left);
    }
    if(root->right)
    {
        cut(root->right);
    }
    if(!root->right&&!root->left&&root->val==0)
    {
        root = nullptr;
    }
}
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        cut(root);
        return root;
    }
};