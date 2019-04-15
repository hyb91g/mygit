//����һ��ͷ���Ϊ root ������, ��дһ�������Խ�����ָ�Ϊ k �������Ĳ��֡�
//ÿ���ֵĳ���Ӧ�þ����ܵ���� : ���������ֵĳ��Ȳ�಻�ܳ��� 1��Ҳ����˵������Щ����Ϊ null��
//��k������Ӧ�ð����������г��ֵ�˳������������������ǰ��Ĳ��ֵĳ���Ӧ�ô��ڻ���ں���ĳ��ȡ�
//����һ���������������������б�
//������ 1->2->3->4, k = 5 // 5 ��� [ [1], [2], [3], [4], null ]


//˼·�����ÿһ���ж೤�������Ƚ�����ضϷ�������

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