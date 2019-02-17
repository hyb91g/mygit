#include"SearchBinaryTree.h"

SBTreeNode* BuyNode(SBTDataType x)
{
	SBTreeNode* new = (SBTreeNode*)malloc(sizeof(SBTreeNode));
	new->_data = x;
	new->_left = NULL;
	new->_right = NULL;
	return new;
}

int BSTreeInsert(SBTreeNode** tree, SBTDataType x)
{
	SBTreeNode* cur, *parent;
	parent = NULL;
	cur = *tree;
	if (cur == NULL)
	{
		*tree = BuyNode(x);
		return 1;
	}
	while (cur)
	{
		if (x > cur->_data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (x < cur->_data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			return 0;
		}
	}
	if (x > parent->_data)
	{
		parent->_right = BuyNode(x);
	}
	else
	{
		parent->_left= BuyNode(x);
	}
	return 1;
}

void BSTreeRemove(SBTreeNode** tree, SBTDataType x)
{
	SBTreeNode* cur, *parent;
	cur = *tree;
	parent = NULL;
	while (cur)
	{
		if (x > cur->_data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (x < cur->_data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else
			break;
	}
	//删除

	//1 叶子结点或只有一个左或右的节点
	if (cur->_left == NULL)
	{
		if (parent == NULL) //根节点
		{
			*tree = cur->_right;
		}
		else
		{
			if (cur == parent->_left)
			{
				parent->_left = cur->_right;
			}
			else if (cur == parent->_right)
			{
				parent->_right = cur->_right;
			}
		}
	}
	else if (cur->_right == NULL)
	{
		if (parent == NULL)
			*tree = cur->_right;
		else
		{
			if (cur == parent->_left)
			{
				parent->_left = cur->_left;
			}
			else if (cur == parent->_right)
			{
				parent->_right = cur->_left;
			}
		}
	}
	//2.有两个孩子节点的结点
	else
	{
		SBTreeNode* rep = cur->_right;
		while (rep->_left)
		{
			rep = rep->_left;
		}
		cur->_data = rep->_data;
		BSTreeRemove(&cur->_right, rep->_data);
	}
	free(cur);
}

SBTreeNode* BSTreeFind(SBTreeNode** tree, SBTDataType x)
{
	SBTreeNode* cur = *tree;
	while (cur)
	{
		if (x > cur->_data)
		{
			cur = cur->_right;
		}
		else if (x < cur->_data)
		{
			cur = cur->_left;
		}
		else
			return cur;
	}
	return NULL;
}

int BSTreeInsertR(SBTreeNode** ppTree, SBTDataType x)
{
	if (*ppTree == NULL)
	{
		*ppTree = BuyNode(x);
		return 1;
	}
	if (x > (*ppTree)->_data)
		return BSTreeInsertR(&(*ppTree)->_right, x);
	else if(x < (*ppTree)->_data)
		return BSTreeInsertR(&(*ppTree)->_left, x);
	else
		return 0;
}

int BSTreeRemoveR(SBTreeNode** ppTree, SBTDataType x)
{
	if (*ppTree == NULL)
		return 0;
	if (x > (*ppTree)->_data)
		return BSTreeRemoveR(&(*ppTree)->_right, x);
	else if (x < (*ppTree)->_data)
		return BSTreeRemoveR(&(*ppTree)->_left, x);
	else
	{
		SBTreeNode* del = *ppTree;
		if ((*ppTree)->_left == NULL)
		{
			*ppTree = (*ppTree)->_right;
			free(del);
		}
		else if ((*ppTree)->_right == NULL)
		{
			*ppTree = (*ppTree)->_left;
			free(del);
		}
		else
		{
			SBTreeNode* replace = (*ppTree)->_right;
			while (replace->_left)
			{
				replace = replace->_left;
			}
			(*ppTree)->_data = replace->_data;
			return BSTreeRemoveR(&(*ppTree)->_right, replace->_data);
		}
		return 1;
	}
}

SBTreeNode* BSTreeFindR(SBTreeNode** ppTree, SBTDataType x)
{
	if (*ppTree == NULL)
		return NULL;
	if (x > (*ppTree)->_data)
		return BSTreeFindR(&(*ppTree)->_right, x);
	else if (x < (*ppTree)->_data)
		return BSTreeFindR(&(*ppTree)->_right, x);
	else
		return *ppTree;
}

void BSTreeDestroy(SBTreeNode** ppTree)
{
	if (*ppTree == NULL)
		return;
	BSTreeInOrder(&(*ppTree)->_left);
	BSTreeInOrder(&(*ppTree)->_right);
	free(*ppTree);
}

void BSTreeInOrder(SBTreeNode** tree)
{
	if (*tree == NULL)
		return;
	BSTreeInOrder(&(*tree)->_left);
	printf("%d ", (*tree)->_data);
	BSTreeInOrder(&(*tree)->_right);
}


void TestBSTree()
{
	int i;
	SBTreeNode* sbt = NULL;
	SBTDataType a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		BSTreeInsertR(&sbt, a[i]);
	}
	BSTreeInOrder(&sbt);
	printf("\n");

	/*BSTreeRemove(&sbt, 0);
	BSTreeRemove(&sbt, 1);
	BSTreeRemove(&sbt, 2);
	BSTreeRemove(&sbt, 3);
	BSTreeRemove(&sbt, 4);
	BSTreeRemove(&sbt, 5);
	BSTreeRemove(&sbt, 6);
	BSTreeRemove(&sbt, 7);
	BSTreeRemove(&sbt, 8);
	BSTreeRemove(&sbt, 9);*/

	BSTreeRemoveR(&sbt, 0);
	BSTreeRemoveR(&sbt, 1);
	BSTreeRemoveR(&sbt, 2);
	BSTreeRemoveR(&sbt, 3);
	BSTreeRemoveR(&sbt, 4);
	BSTreeRemoveR(&sbt, 5);
	BSTreeRemoveR(&sbt, 6);
	BSTreeRemoveR(&sbt, 7);
	BSTreeRemoveR(&sbt, 8);
	BSTreeRemoveR(&sbt, 9);

	BSTreeInOrder(&sbt);
}


int main()
{
	TestBSTree();
	return 0;
}
