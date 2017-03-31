# 25. Reverse Nodes in k-Group

## 描述
给定一个链表，每次翻转k个节点并返回其修改后的链表。
k是正整数，小于或等于链表长度。 如果链表节点的数量不是k的整数倍，则最后的剩余节点保持不变。
您不能直接更改节点中的值，智能修改节点的顺序。
只允许使用常数空间。

例如，
给定链表：1-> 2-> 3-> 4-> 5
对于k = 2，您应该返回：2-> 1-> 4-> 3-> 5
对于k = 3，您应该返回：3-> 2-> 1-> 4-> 5

## 解析
首先遍历一遍链表算出链表长度，然后使用一个大循环，使得操作不会越界，并且可以忽略链表末尾不够k个节点的情况，最后每个小循环中，操作next指针改变前后节点的顺序。虽然使用两层循环，但 平摊分析，每个节点只被操作一次，时间复杂度为O(n).

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
    ListNode *reverseKGroup(ListNode *head, int k) 
    {
        if( head==NULL || k==1 ) 
            return head;
        int sum=0;
        ListNode *preheader = new ListNode(0);
        preheader->next = head;
        ListNode *current = preheader, *forward, *precede = preheader;
        while(current = current->next) 
            sum++;
        while(sum>=k) 
        {
            current = precede->next;
            forward = current->next;
            for(int i=1;i<k;++i) 
            {
                current->next=forward->next;
                forward->next=precede->next;
                precede->next=forward;
                forward=current->next;
            }
            precede = current;
            sum-=k;
        }
        return preheader->next;
    }
};
```

