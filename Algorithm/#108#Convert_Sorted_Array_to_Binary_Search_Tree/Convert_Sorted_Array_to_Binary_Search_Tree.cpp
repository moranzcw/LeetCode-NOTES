#include <iostream>
#include <vector>
#include <cmath>
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
    void dfs(TreeNode *root)
    {
        if(root != NULL)
        {
            dfs(root->left);
            cout<<root->val<<" ";
            dfs(root->right);
        }
        else
            cout<<endl;
    }

    TreeNode* createTree(vector<int> &num,int left, int right)
    {
        if(left > right)
            return NULL;
        int mid = (left+right)/2;
        
        TreeNode *leftNode = createTree(num, left, mid - 1);
        TreeNode *rightNode = createTree(num, mid + 1, right);
        
        TreeNode *node = new TreeNode(num[mid]);
        
        node->left = leftNode;
        node->right = rightNode;

        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
        return createTree(num,0,num.size()-1);
    }
};

int main()
{
    int A1[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> num(A1,A1+10);

    Solution sol;
    TreeNode *result = sol.sortedArrayToBST(num);
    sol.dfs(result);
}