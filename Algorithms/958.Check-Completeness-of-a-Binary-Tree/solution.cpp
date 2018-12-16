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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *t;
        bool flag=false;
        while(q.size()>0){
            t = q.front();
            q.pop();
            if(t==NULL){
                flag = true;
            }else{
                if(flag)
                    return false;
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};
