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
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        if (head == NULL)
            return NULL;
            
        ListNode *q = NULL;
        ListNode *p = head;
        for(int i = 0; i < m - 1; i++)
        {
            q = p;
            p = p->next;
        }
        
        ListNode *end = p;
        ListNode *pPre = p;
        p = p->next;
        for(int i = m + 1; i <= n; i++)
        {
            ListNode *pNext = p->next;
            
            p->next = pPre;
            pPre = p;
            p = pNext;
        }
        
        end->next = p;
        if (q)
            q->next = pPre;
        else
            head = pPre;
        
        return head;
    }
};