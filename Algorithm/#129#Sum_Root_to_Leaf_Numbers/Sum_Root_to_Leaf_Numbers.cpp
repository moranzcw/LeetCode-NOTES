#include <iostream>
#include <vector>
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
    int result;
    void dfs(TreeNode *node,int tempVal)
    {
        tempVal = tempVal*10 + node->val;
        if(node->left || node->right)
        {
            if(node->left)
                dfs(node->left,tempVal);
            if(node->right)
                dfs(node->right,tempVal);
        }
        else
            result += tempVal;
    }

    int sumNumbers(TreeNode *root) 
    {
        result = 0;
        if(root)
            dfs(root,0);
        else
            return 0;
        return result;
    }
};

int main()
{
    TreeNode *treeNode1 = new TreeNode(1);
    TreeNode *treeNode2 = new TreeNode(2);
    TreeNode *treeNode3 = new TreeNode(3);
    treeNode1->left = treeNode2;
    treeNode1->right = treeNode3;

    Solution sol;
    cout<<sol.sumNumbers(treeNode1)<<endl;
    return 0;
}