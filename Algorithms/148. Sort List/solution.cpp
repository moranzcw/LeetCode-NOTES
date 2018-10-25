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
    ListNode *sortList(ListNode *head) 
    {
        if(!head||!head->next)
            return head;
        return mergeSort(head);
    }

    ListNode * mergeSort(ListNode *head)
    {
        if(!head||!head->next)   //just one element
            return head;
        ListNode *p=head, *q=head, *pre=NULL;
        while(q&&q->next!=NULL)
        {
            q=q->next->next;
            pre=p;
            p=p->next;  //divide into two parts
        }
        pre->next=NULL;
        ListNode *lhalf=mergeSort(head);
        ListNode *rhalf=mergeSort(p);  //recursive
        return merge(lhalf, rhalf);   //merge
    }

    ListNode * merge(ListNode *lh, ListNode *rh)
    {
        ListNode *temp=new ListNode(0);
        ListNode *p=temp;

        while(lh&&rh)
        {
            if(lh->val<=rh->val)
            {
                p->next=lh;
                lh=lh->next;
            }
            else
            {
                p->next=rh;
                rh=rh->next;
            }
            p=p->next;
        }
        
        if(!lh)
            p->next=rh;
        else
            p->next=lh;
        p=temp->next;
        temp->next=NULL;
        delete temp;
        return p;
    }
};