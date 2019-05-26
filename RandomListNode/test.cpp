#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;

		//给每个节点后插入一个相同节点
		RandomListNode* cur = pHead;
		while (cur)
		{
			RandomListNode* tmp = new RandomListNode(cur->label);
			tmp->next = cur->next;
			cur->next = tmp;

			cur = cur->next->next;
		}
		//修改每个新增节点的random
		cur = pHead;
		RandomListNode* tmp = cur->next;
		while (cur)
		{
			if (cur->random != nullptr)
				tmp->random = cur->random->next;
			cur = cur->next->next;
			if(cur != nullptr)
				tmp = cur->next;
		}
		//新增节点重新连接,并还原原来的链表
		RandomListNode* ret = pHead->next;
		cur = ret;
		RandomListNode* ccur = pHead;
		while (cur)
		{
			if (cur->next == nullptr)
				break;

			ccur->next = ccur->next->next;
			ccur = ccur->next;

			cur->next = cur->next->next;
			cur = cur->next;
		}
		return ret;
	}
};

int main()
{
	RandomListNode a(1);
	RandomListNode b(2);
	RandomListNode c(3);
	RandomListNode d(4);
	RandomListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	a.random = &c;
	c.random = &e;
	d.random = &b;

	Solution s;
	RandomListNode *ret = s.Clone(&a);
	return 0;
}