#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:

	int High(TreeNode* root)
	{
		TreeNode* cur = root;
		if (!cur)
		{
			return 0;
		}
		return max(High(cur->left), High(cur->right)) + 1;
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL)
			return vv;

		int level = 0;
		TreeNode* cur = root;
		q1.push(cur);
		q2.push(level);

		int ret = High(root);
		vv.resize(ret);


		while (!q1.empty())
		{
			cur = q1.front();
			level = q2.front();

			vv[level].push_back(cur->val);
			q1.pop();
			q2.pop();

			TreeNode* _left = cur->left;
			TreeNode* _right = cur->right;
			if (cur->left != NULL)
			{	
				q1.push(_left);
				q2.push(level+1);
			}
			if (cur->right != NULL)
			{
				q1.push(_right);
				q2.push(level+1);
			}	
		}
		return vv;
	}

private:
	vector<vector<int>> vv;
	queue<TreeNode*> q1;
	queue<int> q2;
};


int main()
{
	Solution s;
	TreeNode a(3);
	TreeNode b(9);
	TreeNode c(20);
	TreeNode d(15);
	TreeNode e(7);
	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;

	vector<vector<int>> vv = s.levelOrder(&a);
	for (auto e : vv[0])
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : vv[1])
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : vv[2])
	{
		cout << e << " ";
	}

	return 0;
}
