//给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
//每部分的长度应该尽可能的相等 : 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
//这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
//返回一个符合上述规则的链表的列表。
//举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]


//思路：算出每一段有多长，按长度将链表截断放入数组

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> v;
		v.resize(k);
		ListNode* tmp = root;
		ListNode* cur = root;
		int count = 0;
		while (tmp)
		{
			count++;
			tmp = tmp->next;
		}
		int m = count % k;

		for (int i = 0; i < k; i++)
		{
			v[i] = cur;
			tmp = cur;
			if (cur == NULL)
			{
				break;
			}

			int n = 0;
			if (m != 0)
			{
				n = count / k + 1;
				m--;
			}
			else
				n = count / k;
			for (int j = 1; j <= n; j++)
			{

				if (j == n)
				{
					cur = tmp->next;
					tmp->next = NULL;
				}
				else
				{
					tmp = tmp->next;
					if (tmp == NULL)
					{
						break;
					}
				}
			}
		}
		return v;
	}
};

int main()
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	//ListNode h(8);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	//g.next = &h;


	ListNode* root = &a;

	Solution s;
	vector<ListNode*> p = s.splitListToParts(root, 3);
	for (auto e : p)
	{
		cout << e->val << endl;
	}

	return 0;
}