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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if(head == NULL)
            return NULL;

        ListNode *temp = head;
        int n = k;
        while(--n && temp != NULL)
            temp = temp->next;

        if(temp == NULL)
            return head;

        ListNode *last = head;
        ListNode *cur = head;
        ListNode *forward = cur->next;

        for(int i=0;i<k-1;i++)
        {
            last = cur;
            cur = forward;
            forward = forward->next;

            cur->next = last;
        }
        head->next = reverseKGroup(forward,k);
        return cur;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *temp = l1;
    for(int i=2;i<5;i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }

    Solution sol;
    ListNode *result = sol.reverseKGroup(l1,2);
    while(result != 0)
    {
        cout << result->val << " ";
        result = result->next;
    }
}