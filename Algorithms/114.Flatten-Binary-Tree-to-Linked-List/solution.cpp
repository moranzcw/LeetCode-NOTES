/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode *pre;
    Solution()
    {
        pre = NULL;
    }
 
    void flatten(TreeNode *root)
    {
        if(root==NULL)
            return;
        TreeNode *lastright=root->right;
        if(pre)
        {
            pre->left=NULL;
            pre->right=root;
        }
        pre=root;
        flatten(root->left);
        flatten(lastright);
    }
};