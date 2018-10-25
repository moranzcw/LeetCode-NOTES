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
    ListNode *deleteDuplicates(ListNode *head) 
    {
        if(head == NULL)
            return head;

        ListNode *last = head;
        ListNode *temp = head->next;
        while(temp != NULL)
        {
            if(temp->val == last->val)
            {
                last->next = temp->next;
            }
            else
            {
                last = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};