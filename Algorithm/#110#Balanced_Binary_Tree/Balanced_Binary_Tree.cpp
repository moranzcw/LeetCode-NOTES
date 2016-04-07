#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
 struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    int isBalancedUtil(TreeNode* root, bool& isValid)
    {
        if(root == NULL) 
            return 0;
        if(!isValid) 
            return -1;
        int leftHeight = isBalancedUtil(root->left, isValid);
        int rightHeight = isBalancedUtil(root->right, isValid);
        if(abs(leftHeight-rightHeight) > 1) 
            isValid = false;
        return max(leftHeight, rightHeight)+1;
    }
    bool isBalanced(TreeNode *root) 
    {
        bool ans = true;
        isBalancedUtil(root, ans);
        return ans;
    }
};

int main()
{
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->right->right = new TreeNode(5);

    Solution sol;
    cout<<sol.isBalanced(head)<<endl;
}