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
    int kthSmallest(TreeNode* root, int k) 
    {
        return InOrder(root,k);
    }
    int InOrder(TreeNode* root,int &k)
    {
        if(root)
        {
            int r1 = InOrder(root->left,k);
            k--;
            if(k==0)
                return root->val;
            int r2 = InOrder(root->right,k);
            return r1+r2;
        }
        return 0;
    }
};