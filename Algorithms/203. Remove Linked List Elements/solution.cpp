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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *temp = NULL;
        while(head != NULL && head->val == val)
        {
            temp = head;
            head = head->next;
            delete(temp);
        }

        if(head == NULL)
            return NULL;

        ListNode *cur = head->next ,*last = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                temp = cur;
                last->next = cur->next;
                cur = cur->next;
                delete temp;
            }
            else
            {
                last = cur;
                cur = cur->next;        
            }
        }
        return head;
    }
};