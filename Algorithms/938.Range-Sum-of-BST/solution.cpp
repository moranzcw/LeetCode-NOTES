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
    int preOrder(TreeNode* root, int L, int R){
        if(root == NULL)
            return 0;
        if(root->val >= L && root->val <= R){
            return root->val + preOrder(root->left,L,R) + preOrder(root->right,L,R);
        }
        if(root->val < L){
            return preOrder(root->right,L,R);
        }
        if(root->val > R){
            return preOrder(root->left,L,R);
        }
        return 0;
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        return preOrder(root,  L,  R);
    }
};
