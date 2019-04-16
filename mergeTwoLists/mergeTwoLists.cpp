//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//思路：大的往小的里插
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* max = l1;
		ListNode* min = l2;
		ListNode* cur;
		if (max->val < min->val)
		{
			max = l2;
			min = l1;
		}
		ListNode* ret = min;
		while (max)
		{
			while (min->val < max->val)
			{
				if (min->next == NULL)
				{
					min->next = max;
					return ret;
				}
				min = min->next;
			}
			cur = max;
			max = max->next;

			cur->next = min->next;
			min->next = cur;
			int tmp = cur->val;
			cur->val = min->val;
			min->val = tmp;
		}
		return ret;
	}
};

int main()
{
	ListNode a(2);
	//ListNode b(-10);
	//ListNode c(-9);
	//ListNode d(-4);
	//ListNode e(1);
	//ListNode f(6);
	//ListNode g(6);
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//e.next = &f;
	//f.next = &g;

	//ListNode d(1);
	//ListNode e(3);
	ListNode h(1);


	Solution s;
	s.mergeTwoLists(&a, &h);
	return 0;
}