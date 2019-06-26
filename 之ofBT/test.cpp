//��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�

//��������ջ��һ��ջ��ջ����ջ��Ԫ�ص�����Ԫ��˳���ŵ���һ��ջ����һ��ջ���Ŵ�
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int>> Print(TreeNode* pRoot) {
		vector<vector<int> > vv;
		vector<int> v;
		if (pRoot == nullptr)
			return vv;
		s1.push(pRoot);
		while (!s1.empty() || !s2.empty())
		{
			while (!s1.empty())
			{
				if(s1.top()->left)
					s2.push(s1.top()->left);
				if (s1.top()->right)
					s2.push(s1.top()->right);
				v.push_back(s1.top()->val);
				s1.pop();
			}
			if (!v.empty())
				vv.push_back(v);
			v.clear();
			while (!s2.empty())
			{
				if (s2.top()->right)
					s1.push(s2.top()->right);
				if (s2.top()->left)
					s1.push(s2.top()->left);
				v.push_back(s2.top()->val);
				s2.pop();
			}
			if (!v.empty())
				vv.push_back(v);
			v.clear();
		}
		return vv;
	}

private:
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
};

int main()
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;

	Solution s;
	s.Print(&t1);

	return 0;
}