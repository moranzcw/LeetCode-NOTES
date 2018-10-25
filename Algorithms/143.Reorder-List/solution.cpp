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
    void reverseList(ListNode *&head) 
    {
        ListNode *h = new ListNode(0);
        ListNode *tmp;
        while (head != NULL) 
        {
            tmp = head->next;
            head->next = h->next;
            h->next = head;
            head = tmp;
        }
        head = h->next;
    }

    void twistList(ListNode *&l1, ListNode *&l2) 
    {
        ListNode *p1, *p2, *tmp;
        p1 = l1; p2 = l2;
        while (p1 != NULL && p2 != NULL) {
            tmp = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next->next;
            p2 = tmp;
        }
    }   

    void reorderList(ListNode *head) 
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL) 
        {
            return;
        }
        ListNode *slow, *fast;
        slow = head; fast = head;
        while (fast != NULL && fast->next != NULL) 
        {
            slow = slow->next;
            if (fast->next->next == NULL) 
            {
                break;
            }
            fast = fast->next->next;
        }
        ListNode *l2 = slow->next;
        slow->next = NULL;
        reverseList(l2);
        twistList(head, l2);
    }
};