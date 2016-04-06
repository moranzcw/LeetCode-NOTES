#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution 
{
public:
    bool dfs(TreeNode *node, int sum, int curSum)
    {
        if (node == NULL)
            return false;
        
        if (node->left == NULL && node->right == NULL)
            return curSum + node->val == sum;
               
        return dfs(node->left, sum, curSum + node->val) 
        || dfs(node->right, sum, curSum + node->val);
    }

    bool hasPathSum(TreeNode *root, int sum) 
    {
        return dfs(root, sum, 0);
    }
};

int main()
{
    return 0;
}