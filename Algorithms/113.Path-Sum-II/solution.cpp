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
    vector<vector<int> > result;
    void dfs(TreeNode *node, int sum, vector<int> curPath, int curSum)
    {
        if (node == NULL)
            return;

        curPath.push_back(node->val);

        if (node->left == NULL && node->right == NULL)
        {
            if(curSum + node->val == sum)
                result.push_back(curPath);
            return;
        }
               
        dfs(node->left, sum, curPath, curSum + node->val);
        dfs(node->right, sum, curPath, curSum + node->val);
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
        vector<int> curPath;
        dfs(root,sum,curPath,0);
        return result;
    }
};