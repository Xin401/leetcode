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
void sol(TreeNode* root,vector<int>&ret)
{
    if(root->left)
    {
        sol(root->left,ret);
    }
    if(root)
    {
        ret.push_back(root->val);
    }
    if(root->right)
    {
        sol(root->right,ret);
    }
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root)
        {
            sol(root,ret);
        }
        return ret;
        
    }
};