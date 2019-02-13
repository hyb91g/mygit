#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode 
{
	BTDataType date;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

// a��һ��ǰ�����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
int BTreeDepth(BTNode* root);
BTNode* BTreeFind(BTNode* root, BTDataType x);
// ����  �ݹ�&�ǵݹ�
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeComplete(BTNode* root);

void TestBinaryTree();


