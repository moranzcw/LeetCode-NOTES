# 21. Merge Two Sorted Lists

## 描述
合并两个已排序的链表，并返回新的已排序链表。 新链表表应直接使用前两个链表的节点。

## 解析
使用两个指针比较，分别推进就行了。

- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *head = new ListNode(0);
        ListNode *point = head;
        while(l1 && l2)
        {
            if(l1->val < l2-> val)
            {
                point->next = l1;
                l1 = l1->next;
            }
            else
            {
                point->next = l2;
                l2 = l2->next;
            }
            point = point->next;
        }
        if(!l1)
            point->next = l2;
        else
            point->next = l1;
        return head->next;
    }
};
```

