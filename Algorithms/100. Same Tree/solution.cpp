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
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if( p == NULL && q == NULL)
            return true;
        else if( p == NULL || q == NULL)
            return false;
        else
        {
            if( p->val == q->val)
                return dfs(p->left,q->left) && dfs(p->right,q->right);
        }
        return false;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
        return dfs(p,q);
    }
};