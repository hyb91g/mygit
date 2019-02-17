#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int SBTDataType;

typedef struct SBTreeNode
{
	SBTDataType _data;
	struct SBTreeNode* _left;
	struct SBTreeNode* _right;
}SBTreeNode;

int BSTreeInsert(SBTreeNode** tree, SBTDataType x);
void BSTreeRemove(SBTreeNode** tree, SBTDataType x);
SBTreeNode* BSTreeFind(SBTreeNode** tree, SBTDataType x);

int BSTreeInsertR(SBTreeNode** ppTree, SBTDataType x);
int BSTreeRemoveR(SBTreeNode** ppTree, SBTDataType x);
SBTreeNode* BSTreeFindR(SBTreeNode** ppTree, SBTDataType x);
void BSTreeDestroy(SBTreeNode** ppTree);

void BSTreeInOrder(SBTreeNode** tree);

void TestBSTree();
