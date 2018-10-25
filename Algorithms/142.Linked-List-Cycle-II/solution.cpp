/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
            return NULL;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            if(fast == slow)
                break;
             slow=slow->next;
             fast=fast->next->next;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;

        fast = head;
        slow = slow->next;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};