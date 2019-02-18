#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef char* SBTKeyType;
typedef int SBTValueType;

typedef struct SBTreeNode
{
	SBTKeyType _key;
	SBTValueType _value;
	struct SBTreeNode* _left;
	struct SBTreeNode* _right;
}SBTreeNode;

int BSTreeInsert(SBTreeNode** tree, SBTKeyType x, SBTValueType value);
void BSTreeRemove(SBTreeNode** tree, SBTKeyType x);
SBTreeNode* BSTreeFind(SBTreeNode** tree, SBTKeyType x);

void BSTreeDestroy(SBTreeNode** ppTree);

void BSTreeInOrder(SBTreeNode** tree);