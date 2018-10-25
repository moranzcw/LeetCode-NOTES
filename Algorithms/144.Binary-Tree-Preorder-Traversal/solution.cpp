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
    vector<int> result;

    void dst(TreeNode *node)
    {
        if(node == NULL)
            return;
        else
        {
            result.push_back(node->val);
            dst(node->left);
            dst(node->right);
        }
    }

    vector<int> preorderTraversal(TreeNode *root) 
    {
        dst(root);
        return result;
    }
};