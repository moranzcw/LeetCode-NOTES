/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define INT_MAX ((int)(~0U>>1))
#define INT_MIN (-INT_MAX - 1)

class Solution 
{
public:
    int max_sum;
    int max_path_sum(TreeNode*root)
    {
        if (!root)
            return 0;
        int i_left = max_path_sum(root->left);
        int i_right = max_path_sum(root->right);
        int sum = root->val;
        if (i_left > 0)
            sum += i_left;
        if (i_right > 0)
            sum += i_right;
        max_sum = max(sum,max_sum);
        return (max(i_left, i_right) > 0) ? (max(i_left, i_right) + root->val) : root->val;
    }

    int maxPathSum(TreeNode *root) 
    {
        max_sum = INT_MIN;

        if (!root)
            return 0;
        max_path_sum(root);
        return max_sum;
    }
};