/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
        ListNode** curNext = &head;
        ListNode* cur = head;
        while(NULL != cur)
        {
            ListNode* temp = cur;
            while(NULL != cur->next && cur->next->val == cur->val)
                cur = cur->next;
            if(cur == temp)
            {
                *curNext = temp;
                curNext = &(*curNext)->next;
            }
            cur = cur->next;
        }
        *curNext = NULL;
        return head;    
    }
};