# 24. Swap Nodes in Pairs

## 描述
给定一个链表，交换每两个相邻的节点并返回其头节点指针。

例如，
给定1-> 2-> 3-> 4，您应该返回2-> 1-> 4-> 3。

您的算法只能使用使用常数空间。 您不能直接修改列表中的值，只能修改节点顺序。

## 解析
按顺序遍历并修改next指针以交换节点即可。

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
    ListNode *swapPairs(ListNode* head) 
    {
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) 
        {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};
```

