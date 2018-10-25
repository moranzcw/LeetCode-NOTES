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
    ListNode *partition(ListNode *head, int x) 
    {
        ListNode *list1 = new ListNode(0);
        ListNode *first = list1;
        ListNode *list2 = new ListNode(0);
        ListNode *second = list2;
        while(head != NULL)
        {
            if(head->val < x)
            {
                first->next = head;
                first = first->next;
            }
            else
            {
                second->next = head;
                second = second->next;
            }
            head = head->next;
        }
        first->next = list2->next;
        second->next = NULL;
        return list1->next;
    }
};