/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *nt;
    TreeNode *cur;
    TreeNode* increasingBST(TreeNode* root) {
        nt = new TreeNode(0);
        cur = nt;
        midOrder(root);
        return nt->right;
    }
    
    int midOrder(TreeNode* node){
        if(node == NULL)
            return 0;
        midOrder(node->left);
        cur->right = new TreeNode(node->val);
        cur = cur->right;
        midOrder(node->right);
        return 0;
    }
};
