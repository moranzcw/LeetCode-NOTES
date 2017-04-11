# 19. Remove Nth Node From End of List

## 描述
给定一个链表，从列表的末尾删除第n个节点并返回链表头指针。
例如，
```
   给定链表： 1->2->3->4->5, 和 n = 2.

   在删除倒数第2个节点之后，链表变成 1->2->3->5.
```
Note:
给定的n始终有效。
尝试一次通过此题。

## 解析
新建立一个节点，其next指针指向链表头节点，该节点作为链表临时头节点，以方便统一处理待删除节点为头节点的情况。
使用两个指针，一前一后遍历链表，前面的指针比后面的指针相差n+1个节点，当前面的指针到达链表尾时，后面的指针刚好到达待删除节点的前一个节点，改变指针将其删除即可。同时，删除临时头节点并返回。

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
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        ListNode *tempHead = new ListNode(0);
        tempHead->next = head;
        ListNode *first = tempHead, *second = tempHead;
        
        for(int i = 0; i < n+1; i++)
            first = first -> next;

        while(first) 
        {
            first = first -> next;
            second = second -> next;
        }
        
        second->next = second->next->next;
        return tempHead->next;
    }
};
```

