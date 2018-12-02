/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* r;
    queue<TreeNode *> q;
    CBTInserter(TreeNode* root) {
        r = root;
        queue<TreeNode *> tq;
        tq.push(r);
        TreeNode *t;
        while(tq.size()>0){
            t = tq.front();
            tq.pop();
            if(t->left != NULL)
                tq.push(t->left);
            if(t->right != NULL)
                tq.push(t->right);
            if(t->left == NULL || t->right == NULL)
                q.push(t);
        }
    }
    
    int insert(int v) {
        TreeNode *t = new TreeNode(v);
        TreeNode *n = q.front();
        if(n->left == NULL){
            n->left = t;
        }else{
            n->right = t;
            q.pop();
        }
        q.push(t);
        return n->val;
    }
    
    TreeNode* get_root() {
        return r;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
