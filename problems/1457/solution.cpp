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
class Solution {
public:
    static void count(TreeNode* &root, vector<int> container,int &ret)
    {
        bool flag = false;
        for(int i = 0;i<container.size();i++)
        {
            if(container[i]==root->val)
            {
                flag = true;
                container.erase(container.begin()+i);
                break;
            }
        }
        if(!flag)
        {
            container.push_back(root->val);
        }
        if(root->right)
        {
            count(root->right,container,ret);
        }
        if(root->left)
        {
            count(root->left,container,ret);
        }
        if(!root->left&&!root->right)
        {
            if(container.size()==0||container.size()==1)
            {
                ret++;
            }
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ret = 0;
        vector<int>container;
        count(root,container,ret);
        return ret;
    }
};