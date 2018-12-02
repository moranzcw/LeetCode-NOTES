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
    bool eq(TreeNode* n1, TreeNode* n2){
        if(n1 == NULL && n2 == NULL)
            return true;
        else if(n1 == NULL || n2 == NULL)
            return false;
        else{
            if(n1->val == n2->val)
                return true;
        }
        return false;
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(eq(root1,root2)){
            if(root1 != NULL){
                return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) 
                    || flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);;
            }
            return true;
        }
        return false;
    }
};
