/**
 * Definition for a binary tree node.
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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root->left == NULL && root->right == NULL)
            return root;
        else if(root->left != NULL && root->right == NULL)
        {
            root->right = invertTree(root->left);
            root->left = NULL;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            root->left = invertTree(root->right);
            root->right = NULL;
        }
        else if(root->left != NULL && root->right != NULL)
        {
            swap(root->left, root->right);
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
        }
        return NULL;
    }
};