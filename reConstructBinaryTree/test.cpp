#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * reConstruct(vector<int> pre, int s_pre, int e_pre, vector<int> vin, int s_vin, int e_vin)
	{
		if (s_pre > e_pre || s_vin > e_vin)
			return NULL;

		TreeNode* root = new TreeNode(pre[s_pre]);

		for (int i = s_vin; i <= e_vin; i++)
		{
			if (root->val == vin[i])
			{
				root->left = reConstruct(pre, s_pre + 1, s_pre - s_vin + i, vin, s_vin, i - 1);
				root->right = reConstruct(pre, i - s_vin + s_pre + 1, e_pre, vin, i + 1, e_vin);
				break;
			}
		}
		return root;
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() != vin.size() || pre.size() == 0 || vin.size() == 0)
			return NULL;
		TreeNode* root = reConstruct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
		return root;
	}
};

int main()
{
	vector<int> pre;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(7);
	pre.push_back(3);
	pre.push_back(5);
	pre.push_back(6);
	pre.push_back(8);
	vector<int> vin;
	vin.push_back(4);
	vin.push_back(7);
	vin.push_back(2);
	vin.push_back(1);
	vin.push_back(5);
	vin.push_back(3);
	vin.push_back(8);
	vin.push_back(6);

	Solution s;
	TreeNode *root = s.reConstructBinaryTree(pre, vin);
	return 0;
}