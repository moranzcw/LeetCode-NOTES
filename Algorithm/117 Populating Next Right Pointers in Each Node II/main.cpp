#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeLinkNode 
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution 
{
public:
    void broadSearch(TreeLinkNode* queueS)
    {
        if(queueS == NULL)
            return;
        TreeLinkNode* newQueueH = NULL;
        TreeLinkNode* newQueueT = NULL;
        while(queueS)
        {
            if(queueS->left)
            {
                if(newQueueH == NULL)
                    newQueueH = queueS->left;
                if(newQueueT == NULL)
                    newQueueT = queueS->left;
                else{
                    newQueueT->next = queueS->left;
                    newQueueT = queueS->left;
                }
            }
            if(queueS->right)
            {
                if(newQueueH == NULL)
                    newQueueH = queueS->right;
                if(newQueueT == NULL)
                    newQueueT = queueS->right;
                else{
                    newQueueT->next = queueS->right;
                    newQueueT = queueS->right;
                }

            }
            queueS = queueS->next;
        }
        broadSearch(newQueueH );
    }

    void connect(TreeLinkNode *root) 
    {
        TreeLinkNode* queueS = root;
        broadSearch(queueS);
    }
};

int main()
{
    TreeLinkNode *p = new TreeLinkNode(1);
    p->left = new TreeLinkNode(2);
    p->right = new TreeLinkNode(3);
    p->left->left = new TreeLinkNode(4);
    p->left->right = new TreeLinkNode(5);
    p->right->left = new TreeLinkNode(6);
    p->right->right = new TreeLinkNode(7);

    Solution sol;
    sol.broadSearch(p);

    return 0;
}