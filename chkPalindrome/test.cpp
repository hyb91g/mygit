#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		stack<ListNode*> s;
		ListNode* cur = A;
		while (cur)
		{
			s.push(cur);
			cur = cur->next;
		}
		while (A && A->val == s.top()->val)
		{
			A = A->next;
			s.pop();
		}
		if (A == nullptr)
			return true;
		else
			return false;
	}
};

int main()
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(2);
	ListNode e(1);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	PalindromeList s;
	cout << s.chkPalindrome(&a) << endl;

	return 0;
}