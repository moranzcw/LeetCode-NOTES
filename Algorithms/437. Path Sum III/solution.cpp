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
    int dfs(TreeNode* root, int &sum, int tempSum)
    {
        if(!root)
            return 0;
        tempSum += root->val;
        int flag = 0;
        if(tempSum == sum)
            flag = 1;
        return flag + dfs(root->left,sum,tempSum) + dfs(root->right,sum,tempSum);
    }
    
    int pathSum(TreeNode* root, int sum) 
    {
        if(!root)
            return 0;
        return dfs(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};