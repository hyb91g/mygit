#include"Test.h"


SBTreeNode* BuyNode(SBTKeyType key, SBTValueType value)
{
	SBTreeNode* new = (SBTreeNode*)malloc(sizeof(SBTreeNode));
	new->_key = (char*)malloc(strlen(key) + 1);
	strcpy(new->_key, key);
	new->_value = value;
	new->_left = NULL;
	new->_right = NULL;
	return new;
}

int BSTreeInsert(SBTreeNode** tree, SBTKeyType key, SBTValueType value)
{
	SBTreeNode* cur, *parent;
	parent = NULL;
	cur = *tree;
	if (cur == NULL)
	{
		*tree = BuyNode(key, value);
		return 1;
	}
	while (cur)
	{
		if (strcmp(key, (*tree)->_key))
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (strcmp((*tree)->_key, key))
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			return 0;
		}
	}
	if (strcmp(key, parent->_key))
	{
		parent->_right = BuyNode(key, value);
	}
	else
	{
		parent->_left = BuyNode(key, value);
	}
	return 1;
}

void BSTreeRemove(SBTreeNode** tree, SBTKeyType key)
{
	SBTreeNode* cur, *parent;
	cur = *tree;
	parent = NULL;
	while (cur)
	{
		if (strcmp(key, cur->_key))
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (strcmp(cur->_key, key))
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
		if (parent == NULL)
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
		cur->_key = rep->_key;
		BSTreeRemove(&cur->_right, rep->_key);
	}
	free(cur);
}

SBTreeNode* BSTreeFind(SBTreeNode** tree, SBTKeyType key)
{
	SBTreeNode* cur = *tree;
	while (cur)
	{
		if (strcmp(key, cur->_key))
		{
			cur = cur->_right;
		}
		else if (strcmp(cur->_key, key))
		{
			cur = cur->_left;
		}
		else
			return cur;
	}
	return NULL;
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
	printf("%s:%d\n", (*tree)->_key, (*tree)->_value);
	BSTreeInOrder(&(*tree)->_right);
}



//void TestBSTree1()
//{
//	char str[10];
//	SBTreeNode* pTree = NULL;
//	BSTreeInsert(&pTree, "insert");
//	BSTreeInsert(&pTree, "sort");
//	BSTreeInsert(&pTree, "find");
//	BSTreeInsert(&pTree, "tree");
//	BSTreeInsert(&pTree, "destroy");
//
//	while (1)
//	{
//		scanf("%s", str);
//		if (BSTreeFind(&pTree, str))
//		{
//			printf("正确的单词\n");
//		}
//		else
//		{
//			printf("错误的单词\n");
//		}
//	}
//}

void TestBSTree2()
{
	char str[10];
	SBTreeNode* pTree = NULL;
	while (1)
	{
		SBTreeNode* node;
		scanf("%s", str);
		if (strcmp(str, "exit") == 0)
		{
			break;
		}

		node = BSTreeFind(&pTree, str);
		if (node)
		{
			node->_value++;
		}
		else
		{
			BSTreeInsert(&pTree, str, 1);
		}
	}

	BSTreeInOrder(&pTree);
}

int main()
{
	//TestBSTree1();
	TestBSTree2();
	return 0;
}