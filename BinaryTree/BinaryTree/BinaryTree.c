#include"BinaryTree.h"
#include"queue.h"
#include"Stcak.h"


BTNode* BuyBTNode(BTDataType x)
{
	BTNode* Node = (BTNode*)malloc(sizeof(BTNode));
	Node->date = x;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
		return NULL;
	else
	{
		BTNode* NewNode = BuyBTNode(a[*pi]);

		++(*pi);
		NewNode->left = BinaryTreeCreate(a, n, pi);

		++(*pi);
		NewNode->right = BinaryTreeCreate(a, n, pi);
		
		return NewNode;
	}
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left)
		+ BinaryTreeSize(root->right)
		+ 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1)
		+ BinaryTreeLevelKSize(root->right, k - 1);
}

int BTreeDepth(BTNode* root)
{
	int lefthigh = 0, righthigh = 0;
	if (root == NULL)
		return 0;
	lefthigh = BTreeDepth(root->left);
	righthigh = BTreeDepth(root->right);
	return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
}

BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL)
		return NULL;
	if (root->date == x)
		return root;
	ret = BTreeFind(root->left, x);
	if (ret)
	{
		return ret;
	}
	ret = BTreeFind(root->right, x);	
	if (ret)
	{
		return ret;
	}
	return NULL;
}

// 遍历  递归&非递归
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->date);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->date);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->date);

}
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		printf("%d\n", root->date);
		return;
	}
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		if (root->left)
		{
			QueuePush(&q, root->left);
		}
		if (root->right)
		{
			QueuePush(&q, root->right);
		}
		printf("%c ", root->date);
		QueuePop(&q);
		if(QueueEmpty(&q))
			root = QueueFront(&q);
	}
}

int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	BTNode* front;
	QueueInit(&q);
	if(root)
		QueuePush(&q, root);
	while (QueueEmpty(&q) != 0)
	{
		front = QueueFront(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
			break;
		QueuePop(&q);
	}
	while (QueueEmpty(&q) != 0)
	{
		front = QueueFront(&q);

		if (front)
		{
			return 0;
		}
		QueuePop(&q);
	}
	return 1;
}

void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack s;
	BTNode* cur, *top;
	StackInit(&s);
	cur = root;
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			printf("%c ", cur->date);
			StackPush(&s, cur);
			cur = cur->left;
		}
		top = StackTop(&s);
		StackPop(&s);

		cur = top->right;
	}
}
void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack s;
	BTNode* cur, *top;
	StackInit(&s);
	cur = root;
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		top = StackTop(&s);
		StackPop(&s);
		printf("%c ", top->date);

		cur = top->right;
	}
}
void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack s;
	BTNode*cur, *top, *prev;
	StackInit(&s);
	cur = root;
	prev = NULL;
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}

		top = StackTop(&s);
		if (top->right == NULL || prev == top->right)
		{
			printf("%c ", top->date);
			prev = StackTop(&s);
			StackPop(&s);
		}
		else
		{
			cur = top->right;
		}
	}
}


void TestBinaryTree()
{
	//char array[] = { 'A', 'B', 'D', '#', '#', 'X', '#', '#', 'C',
	//	'E', '#', '#', 'F', '#', '#' };
	char array[] = { '1', '#', '4', '3', '#', '#', '2'};
	int i = 0;
	BTNode* ret;
	int comp;
	BTNode* tree = BinaryTreeCreate(array, sizeof(array) / sizeof(BTDataType), &i);

	printf("%d\n", BinaryTreeSize(tree));
	printf("%d\n", BinaryTreeLeafSize(tree));
	printf("%d\n", BinaryTreeLevelKSize(tree, 2)); 
	printf("%d\n", BTreeDepth(tree));
	ret = BTreeFind(tree, 'E');
	printf("%c\n", ret->date);
	ret = BTreeFind(tree, 'Z');
	printf("%p\n", ret);

	/*BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreePrevOrderNonR(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");*/
	BinaryTreeInOrderNonR(tree);
	printf("\n");
	/*BinaryTreePostOrder(tree);
	printf("\n");
	BinaryTreePostOrderNonR(tree);
	printf("\n");
	BinaryTreeLevelOrder(tree);
	printf("\n");
	comp = BinaryTreeComplete(tree);
	if (comp == 1)
		printf("是完全二叉树\n");
	else if (comp == 0)
		printf("不是完全二叉树\n");*/
	BinaryTreeDestory(tree);
	tree = NULL;
	
	printf("\n");
}

int main()
{
	TestBinaryTree();
	return 0;
}