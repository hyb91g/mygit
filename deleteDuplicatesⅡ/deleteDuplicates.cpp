//给定一个排序链表，删除所有重复的元素。

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
		if (head == NULL || head->next ==NULL)
		{
			return head;
		}
		if (head->next->next == NULL && head->val == head->next->val)
			return NULL;
		else if (head->next->next == NULL && head->val != head->next->val)
		{
			return head;
		}

		int count = 0;   //若第一个就开始重复，就标记
		ListNode* del = head;
		ListNode* cur = head;
		if (cur->val == cur->next->val)
		{
			count = 1;
		}
		if (cur->val == cur->next->next->val)
		{
			count = 2;
		}

		while (cur->next && cur->next->next)
		{
			while (cur->next->val != cur->next->next->val)
			{
				cur = cur->next;
				if (cur->next->next == NULL)
				{
					if (count == 1)
						head = head->next->next;
					if (count == 2)
						head = head->next;
					return head;
				}
			}
			
			del = cur->next;
			while (del->val == del->next->val)
			{
				del->next = del->next->next;
				if (del->next == NULL)
					break;
			}
			cur->next = del->next;
		}
		if (count == 1)
			head = head->next->next;
		if (count == 2)
			head = head->next;
		return head;
	}
};
int main()
{
	ListNode p(1);
	ListNode q(2);

	ListNode a(2);
	//ListNode b(2);
	//ListNode c(3);
	//ListNode d(3);
	//ListNode e(4);
	//ListNode f(4);
	//ListNode g(5);
	p.next = &q;
	q.next = &a;
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//e.next = &f;
	//f.next = &g;

	Solution s;
	s.deleteDuplicates(&p);
	return 0;
}