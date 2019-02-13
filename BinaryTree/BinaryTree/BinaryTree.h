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

// a是一个前序遍历的数组
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
int BTreeDepth(BTNode* root);
BTNode* BTreeFind(BTNode* root, BTDataType x);
// 遍历  递归&非递归
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeComplete(BTNode* root);

void TestBinaryTree();


