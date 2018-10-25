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
    int isBalancedUtil(TreeNode* root, bool& isValid)
    {
        if(root == NULL) return 0;
        if(!isValid) return -1;
        int leftHeight = isBalancedUtil(root->left, isValid);
        int rightHeight = isBalancedUtil(root->right, isValid);
        if(abs(leftHeight-rightHeight) > 1) isValid = false;
        return max(leftHeight, rightHeight)+1;
    }
    bool isBalanced(TreeNode *root) 
    {
        bool ans = true;
        isBalancedUtil(root, ans);
        return ans;
    }
};