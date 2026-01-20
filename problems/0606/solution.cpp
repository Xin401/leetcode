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
void ans(TreeNode* root,string& str)
{
    if(root!=nullptr)
    {
        str+=to_string(root->val);
    }
    
    if(root->left)
    {
        str.push_back('(');
        ans(root->left,str);
        str.push_back(')');
    }
    
    if(root->right)
    {
        if(!root->left)
        {
            str.push_back('(');
            str.push_back(')');
        }
        str.push_back('(');
        ans(root->right,str);
        str.push_back(')');
    }
}
class Solution {
public:
    string tree2str(TreeNode* root) {
        string str;
        ans(root,str);
        return str;
    }
};