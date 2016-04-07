#include <iostream>
#include <algorithm>
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
    int maxDepth(TreeNode *root) 
    {
        if(root == NULL)
            return 0;
        else
            return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

int main()
{
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->left->left = new TreeNode(4);

    Solution sol;
    cout<<sol.maxDepth(p)<<endl;
    return 0;
}