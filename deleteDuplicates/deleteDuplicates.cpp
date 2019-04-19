//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == NULL)
		{
			return head;
		}
		ListNode* cur = head;
		while (cur->next)
		{
			int a = cur->val;
			while (cur->next->val == a)
			{
				cur->next = cur->next->next;
				if (cur->next == NULL)
				{
					return head;
				}
			}
			cur = cur->next;
		}
		return head;
	}
};
int main()
{
	ListNode a(1);
	ListNode b(1);
	ListNode c(2);
	ListNode d(3);
	ListNode e(3);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	Solution s;
	s.deleteDuplicates(&a);
	return 0;
}