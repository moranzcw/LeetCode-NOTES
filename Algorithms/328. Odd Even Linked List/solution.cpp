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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode *oddList = new ListNode(0);
        ListNode *evenList = new ListNode(0);
        
        ListNode *oddIte = oddList;
        ListNode *evenIte = evenList;
        
        for(int i=1;head != NULL;i++)
        {
            if(i & 0x01) // 计数，判断奇偶
            {
                oddIte->next = head;
                oddIte = oddIte->next;
                head = head->next;
                oddIte->next = NULL;
            }
            else
            {
                evenIte->next = head;
                evenIte = evenIte->next;
                head = head->next;
                evenIte->next = NULL;
            }
        }
        
        oddIte->next = evenList->next; //偶数链接到奇数链后
        head = oddList->next;
        
        delete oddList, evenList; // 回收两个头节点
        return oddList->next;
    }
};