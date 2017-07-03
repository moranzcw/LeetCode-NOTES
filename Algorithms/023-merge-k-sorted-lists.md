# 23. Merge k Sorted Lists

## 描述
合并k个已排序的链表，并返回一个新的已排序链表。 分析并描述其复杂度。

## 解析
和 [21. Merge Two Sorted Lists] 一样，共使用k个指针指向各链表，比较k个指针，得到最小的节点，接入新链表，再推进该指针。
然而，每得到一个新节点，最多可能要比较k次，有太多重复操作，可以使用一个优先队列来保存k个指针的节点，这样，可以将比较操作降低到常数级别。

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
struct Compare
{
	bool operator()(const ListNode*p, const ListNode* q)const{
		return p->val > q->val;
	}
};

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		int length = lists.size();
		ListNode *head = new ListNode(0);
		ListNode *pointer = head;
		priority_queue<ListNode*, vector<ListNode*>, Compare> listQueue;
		
		for (int i=0; i<length; i++)
		{
			if (lists[i])
				listQueue.push(lists[i]);
		}
		
		while (listQueue.size() > 0)
		{
			ListNode* tempNode = listQueue.top();
			listQueue.pop();
			pointer->next = tempNode;
			pointer = pointer->next;
			if (tempNode->next)
				listQueue.push(tempNode->next);
		}
		pointer->next = NULL;
		return head->next;
	}
};

	


```

