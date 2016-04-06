#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
    ListNode *insertionSortList(ListNode *head) 
    {
        if (head == NULL) 
            return head;
        
        ListNode* curr = head -> next;
        head -> next = NULL;
        
        while(curr != NULL)
        {
            ListNode* tmpHead = head;
            ListNode* prev = NULL;
            ListNode* next = curr -> next;
            while(tmpHead != NULL && tmpHead -> val <= curr -> val)
            {
                prev = tmpHead;
                tmpHead = tmpHead -> next;
            }
            
            if(prev != NULL)
            {
                //insert
                if(prev -> next)
                {
                    curr -> next = prev -> next;
                    prev -> next = curr;
                }
                else
                {
                    prev -> next = curr;
                    curr -> next = NULL;
                }
            }
            else
            {
                curr -> next = head;
                head = curr;
            }
            curr = next;
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(10);
    ListNode *temp = head;
    for(int i=9;i>0;i--)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    Solution sol;
    head = sol.insertionSortList(head);

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}