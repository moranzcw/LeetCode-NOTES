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
    int dfs(TreeNode *root, vector<string> &result, string temp)
    {
        temp += to_string(root->val);
        if(!root->right && !root->left)
        {
            result.push_back(temp);
            return 0;
        }
        if(root->left)
            dfs(root->left,result,temp+"->");
        if(root->right)
            dfs(root->right,result,temp+"->");
        return 0;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        string temp;
        if(root)
            dfs(root,result,temp);
        return result;
    }
};